#include <msp430f249.h>
#include "key.h"
#include "tube.h"
#define uchar unsigned char
#define uint unsigned int


uchar value = 0x00;

void delayus(uint t)
{
  uint i;
  while(t--)
  {
    for(i=1330;i>0;i--);
  }
}

void initialize()
{
  WDTCTL = WDTPW + WDTHOLD;
  
  P1DIR = 0xFF;
  P1SEL = 0x00;
  P1OUT = 0x00;
  
  P3DIR = 0x00;
  P3SEL = 0x00;
  
  P4DIR = 0xFF;
  P4OUT = 0x00;
  
}

void main()
{
  uchar key;
  initialize();
  while(1)
  {
    key = Get_Key();
    Process_Key(key);
    tube1();
    tube2();
    delayus(20);
  }
}
