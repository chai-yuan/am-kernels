#include <am.h>
#include <klib-macros.h>

#define GPIO_BASE 0x10002000L
#define GPIO_LED  0x0
#define GPIO_SEG  0x8

int main(const char *args) {
  unsigned char led = 1;
  unsigned int seg = 0;
  while(1){
      *(volatile char *)(GPIO_BASE + GPIO_LED) = led;
      *(volatile unsigned int *)(GPIO_BASE + GPIO_SEG) = seg;
      
      for(int i=0;i<10000000;i++);
      
      led = (led << 1) | 1;
      seg ++;
  }
  return 0;
}
