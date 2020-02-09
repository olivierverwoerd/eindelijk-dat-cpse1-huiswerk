#include "hwlib.hpp"
#include <algorithm>
#include "clock.hpp"
#include <array>

constexpr double pow( double g, int n ){
   double result = 1;
   while( n > 0 ){
       result *= g;
       --n;
   }
   return result;
}

constexpr double fac( int n ){
   double result = 1;
   while( n > 0 ){
       result *= n;
       --n;
   }
   return result;
}

constexpr double sin( double a ){
   return 
      a 
      - pow( a, 3 ) / fac( 3 ) 
      + pow( a, 5 ) / fac( 5 ) 
      - pow( a, 7 ) / fac( 7 )
      + pow( a, 9 ) / fac( 9 ) 
      - pow( a, 11 ) / fac( 11 ) 
      + pow( a, 13 ) / fac( 13 );
}

constexpr double radians_from_degrees( int degrees ){
   return 2 * 3.14 * ( degrees / 360.0 );
}

constexpr double scaled_sine_from_degrees( int degrees ){
   return sin( radians_from_degrees( degrees ));
}

class lookup {
private:    
   std::array< double, 360 > values;

public: 

   constexpr lookup():
      values {}
   {   
      for( int i = 0; i < 360; ++i ){
          values[ i ] = scaled_sine_from_degrees( i );
      }
   }

   constexpr int getsin( int n ) const {
      return values[ n ];    
   }

   constexpr int getcos( int n ) const {
      if (n < 90){
         values[ n + 270 ];
      }
      return values[ n-90 ];    
   }
};


namespace target = hwlib::target;
// Provide power for the oled for lazy setup
namespace hwlib {
   class pin_fixed {
   public:    
	pin_fixed( pin_out & pin, bool v ){
		pin.set( v );
	} 
   };
class waiter_ms {
   public:
	  waiter_ms( int ms ){
		 hwlib::wait_ms( ms );
	  }
   };
};

   // The OLED display is connected in a very funny way:
   // the I2C pins are reversed, and two GPIO pins are
   // (mis-) used as ground and power for the display.
   // This works, and makes it very easy to connect the LCD,
   // but don't take this as an advice to connect peripherals is this way
   // unless you know very well what you are doing.
class oled_buffered_d18_d21 {
   target::pin_oc scl, sda;
   hwlib::i2c_bus_bit_banged_scl_sda i2c_bus;
   target::pin_out pin_gnd, pin_vcc;
   hwlib::pin_fixed pin_gnd_fixed, pin_vcc_fixed;
   hwlib::waiter_ms wait_ms;
   
public:
   hwlib::glcd_oled_buffered oled;

   oled_buffered_d18_d21():
	  scl( target::pins::sda ),
	  sda( target::pins::scl ),
	  i2c_bus( scl, sda ),
	  pin_gnd( target::pins::d19 ),
	  pin_vcc( target::pins::d18 ),
	  pin_gnd_fixed( pin_gnd, 0 ),
	  pin_vcc_fixed( pin_vcc, 1 ),
	  wait_ms( 200 ),
	  oled( i2c_bus, 0x3c )
   {}   
};

/* @brief main
 * set the oled class and draw clock
 */
int main( void ){	
   
   // kill the watchdog & wait for the PC console to start
   WDT->WDT_MR = WDT_MR_WDDIS;
   hwlib::wait_ms( 500 );   
   
	auto hwoled     = oled_buffered_d18_d21();
	auto & oled = hwoled.oled;
	auto font    = hwlib::font_default_16x16();
	auto display = hwlib::window_ostream( oled, font );
	oled.clear();
	oled.flush();
   constexpr lookup sinusses;
   
   int clock_radius = 23;
   } //scaled_sine_from_degrees
   for(;;){
   auto time = hwlib::now_us()/1000'000;
   auto seconds = time % 60;
   auto minutes = ( time / 60 ) % 60;
   auto hours   = ( time / ( 60 * 60 )) % 12;
   oled.clear();
   display << "\t0000" << hours << ':'<< minutes << ':'<< seconds;
   clock_draw_line( oled, midpoint, getsin(int(5.9*seconds)), getsin(int(5.9*seconds)), clock_radius -  3 , 4);
   clock_draw_line( oled, midpoint, getsin(int(5.9*minutes)), getsin(int(5.9*minutes)), clock_radius -  8, 4);
   clock_draw_line( oled, midpoint, getsin(int(5.9*hours)), getsin(int(5.9*hours)),  clock_radius - 14, 4);
   oled.flush();    
   hwlib::wait_ms( 500 );  
   }
   
}