#include <msp430f249.h>
#define uchar unsigned char
#define uint unsigned int

extern uchar value;

uchar Get_Key(void)
{
  uchar key = 0;
  uchar input;
  input = P3IN & 0x07;
  if (input != 0x07)
  {
    if (input == 0x06)
    {
      key = 1;
    }
    else if (input == 0x05)
    {
      key = 2;
    }
    else if (input == 0x03)
    {
      key = 3;
    }
    return key;
  }
  return key;
}

void Process_Key(uchar key)
{
  if (key != 0)
  {
    switch (key)
    {
    case 1:
      if (value == 0xFF) break;
      ++value;
      break;
    case 2:
      if (value == 0x00) break;
      --value;
      break;
    case 3:
      value = 0x00;
      break;
    }
  }
}