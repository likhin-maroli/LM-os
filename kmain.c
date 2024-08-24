const int VGA_WIDTH = 80;
const int VGA_HEIGHT = 25;
#include "gdt.h"


volatile unsigned short* vga_buffer = (unsigned short*)0xB8000;



void write_char(int x, int y, char c, unsigned char color)
  {
  
  vga_buffer[y * VGA_WIDTH + x] = (color << 8) | c;
   
  }
  
 void write_string(int x, int y, const char* str, unsigned char color)
 
 {
     int pos=0;
     while(str[pos] != '\0')
     {
     write_char(x+pos, y, str[pos], color);
     
     pos++;
     }
     
  }
  
  
 

int kernel_main()

{

 gdt_install();
 
 write_string(1,1, "Hello world", 0x07);
 write_string(1,2, "Likhin here !", 0x01);

 __asm__ __volatile__("hlt");
 return 0;

}
