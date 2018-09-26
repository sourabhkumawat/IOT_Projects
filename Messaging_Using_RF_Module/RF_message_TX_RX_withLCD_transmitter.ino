//RF_Message_TX_RX_withLCD_TRANSMITTER

#include <VirtualWire.h>

//const int led_pin = 13;
const int transmit_pin = 12;
const int receive_pin = 2;
const int transmit_en_pin = 3;

char cad[100];
int i=0;

void setup()
{
    Serial.begin(9600); 
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    // Initialize the IO and ISR
    vw_setup(2000); // Bits per sec
       Serial.println("End with \".\" each data \n");
    // pinMode(led_pin, OUTPUT);
}

void loop()
{

int val = analogRead(A0);
Serial.println(val);
int i = 0;
while(val != 0)
{
  cad[i] = val%10;
  val = val/10;
  i++;
}

//if( cad[i-1] == '.')
//{
  
  Serial.println(  cad[0]);
  //digitalWrite(led_pin, HIGH);
   cad[i] = '\0'; 
   vw_send((byte *)cad, strlen(cad)); 
   vw_wait_tx();
   delay(2000);
   //digitalWrite(led_pin, LOW);
  //}
 
 }
