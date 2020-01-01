#include "hwlib.hpp"

extern "C" {

   // don't chance this function: it is the bridge 
   // between the C and assembler 'world' and C++.
   void put_char( char c ){
      hwlib::cout << c;
   }
   void print_asciz( const char * p );
};
 
// Do not change the code below. Execution starts in C++, 
// then continues in application(). Make your modifications 
// there in the extern "C" { . . . }; part, and in the separate .asm file.
int main(){	        
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
    
   // wait for the PC console to start
   hwlib::wait_ms( 500 );
   //is al een keer goedgekeurd https://docs.google.com/spreadsheets/d/1fcJXO1LDSrwbGcgLm2OsdWsJIqAv3jDYOJt9XVCAxog/edit#gid=592690399
   print_asciz( "Hello world, the ANSWER is 42! @[]`{}~\nand another string to show the newline" );
}

