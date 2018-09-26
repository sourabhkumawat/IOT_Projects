#include <LedControl.h>

int DIN = 12;
int CS =  10;
int CLK = 11;


byte f[8]=  {0x00,0x78,0x40,0x40,0x70,0x40,0x40,0x00};
  byte o[8]=  {0x00,0x18,0x24,0x42,0x42,0x24,0x18,0x00};
  byte r[8]=  { 0x00,0x78,0x48,0x50,0x60,0x50,0x48,0x00};
  byte s[8]=  { 0x00,0x78,0x40,0x40,0x78,0x08,0x08,0x78};
  byte k[8]=  { 0x00,0x44,0x48,0x50,0x60,0x50,0x48,0x44};
 
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,9);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 

    printByte(f);     
   delay(1000);

printByte(o);     
   delay(1000);

   printByte(r);     
   delay(1000);

   printByte(s);     
   delay(1000);

   printByte(k);     
   delay(1000);
                                                         
}

  
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

