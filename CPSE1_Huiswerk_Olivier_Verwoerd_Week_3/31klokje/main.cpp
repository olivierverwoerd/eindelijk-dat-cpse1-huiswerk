#include "hwlib.hpp"
#include <algorithm>
#include <math.h>
#include "math.hpp"
#include "clock.hpp"

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
   for(;;){
	   clock_draw( hwoled.oled, display, hwlib::location(64,40), 23, hwlib::now_us()/1000'000);
         hwlib::wait_ms( 500 );  
   }
   
}