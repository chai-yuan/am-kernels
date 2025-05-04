#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

#define GPIO_BASE 0x10002000L
#define GPIO_LED  0x0
#define GPIO_SEG  0x8

int main(const char *args) {
  unsigned char led = 0x12;
  unsigned int seg = 0;
  while(1){
      printf("Hello from crrv!\n");
      *(volatile char *)(GPIO_BASE + GPIO_LED) = led;
      *(volatile unsigned int *)(GPIO_BASE + GPIO_SEG) = seg;
      
      for(int i=0;i<1000000;i++);
      
      led = (led << 3) ^ led;
      seg ++;
  }
  return 0;
}
