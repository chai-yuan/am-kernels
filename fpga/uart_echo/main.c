#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

#define GPIO_BASE 0x10002000L
#define GPIO_LED  0x0
#define GPIO_SEG  0x8

int main(const char *args) {
  AM_UART_RX_T rx;
  
  while(1){
    rx.data = 0xff;
    ioe_read(AM_UART_RX,&rx);
    
    for(volatile int i=0;i<2000000;i++);
    
    if(rx.data == 0xff) {
    	printf("get null\n");
    }else {
    	printf("get : %c\n",rx.data);
    }
  }
  return 0;
}
