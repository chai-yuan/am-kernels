#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

#define GPIO_BASE 0x10002000L
#define GPIO_LED  0x0
#define GPIO_SEG  0x8

int main(const char *args) {
  volatile unsigned int *addr = (unsigned int *)0x80000000;
  volatile unsigned int *addr2 = (unsigned int *)0x80000004;
  
  while(1){
    *addr = 305419896;
    
    *addr2 = 0x0badbeef;
    
    printf("get : %d %d\n", *addr, *addr2);
    
    for(volatile int i=0;i<100000;i++);
  }
  return 0;
}
