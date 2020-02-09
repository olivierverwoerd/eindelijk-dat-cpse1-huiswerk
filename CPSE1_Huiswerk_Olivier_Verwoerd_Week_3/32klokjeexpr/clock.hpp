namespace hwlib {
   constexpr location operator/( const location & lhs, int rhs ){
	  return location( lhs.x / rhs, lhs.y / rhs );
   }

}

void clock_draw_line( 
   hwlib::glcd_oled_buffered & oled, 
   const hwlib::location & midpoint,
   int sindegrees,
   int cosdegrees,
   int radius,
   int radiusstartpoint)
   {  
   hwlib::line( 
      midpoint + hwlib::location(
         sindegrees*radiusstartpoint,
         cosdegrees*radiusstartpoint),
      midpoint + hwlib::location(
         sindegrees*radius,
         cosdegrees*radius
   )).draw( oled );   
}
