namespace hwlib {
   constexpr location operator/( const location & lhs, int rhs ){
	  return location( lhs.x / rhs, lhs.y / rhs );
   }

}

void clock_draw_line( 
   hwlib::glcd_oled_buffered & oled, 
   const hwlib::location & midpoint,
   int degrees,
   int radius,
   int radiusstartpoint)
   {  
   hwlib::line( 
      midpoint + hwlib::location(
         scaled_sine_from_degrees( degrees, radiusstartpoint ),
         scaled_cosine_from_degrees( degrees, radiusstartpoint )),
      midpoint + hwlib::location(
         scaled_sine_from_degrees( degrees, radius ),
         scaled_cosine_from_degrees( degrees, radius )
   )).draw( oled );   
}

void clock_draw_markers( 
   hwlib::glcd_oled_buffered & oled, 
   const hwlib::location & midpoint,
   int clock_radius,
   int circle_radius
){
   for( int angle = 0; angle < 360; angle += 30 ){
	clock_draw_line( oled, midpoint, angle, clock_radius -  3, clock_radius - 5 );
   }
}   

void clock_draw(
   hwlib::glcd_oled_buffered & oled,
   hwlib::window_ostream & display, 
   const hwlib::location & midpoint,
   int clock_radius,
   int time
){  
   oled.clear();   
   auto seconds = time % 60;
   auto minutes = ( time / 60 ) % 60;   
   auto hours   = ( time / ( 60 * 60 )) % 12;
   display << "\t0000" << hours << ':'<< minutes << ':'<< seconds;
   clock_draw_markers( oled, midpoint, clock_radius, 1 );
   clock_draw_line( oled, midpoint,  5.9 * seconds, clock_radius -  3 , 4);
   clock_draw_line( oled, midpoint, 5.9 * minutes, clock_radius -  8, 4);
   clock_draw_line( oled, midpoint, 29.5 * hours,  clock_radius - 14, 4);
   oled.flush();    
}