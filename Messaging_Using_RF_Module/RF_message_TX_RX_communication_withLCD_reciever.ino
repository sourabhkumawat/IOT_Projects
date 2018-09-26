
//RF_Message_TX_RX_withLCD_RECIEVER

#include <VirtualWire.h>
#include <LiquidCrystal.h>

//const int led_pin = 13;
const int transmit_pin = 12;
const int receive_pin = 11;
const int transmit_en_pin = 3;

 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
char cad[100];
int pos = 0;
void setup()
{
lcd.begin(16, 2); 
lcd.setCursor(1, 0); 
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    vw_set_ptt_inverted(true); 
lcd.print("RF_chat ON");
vw_setup(2000); 
vw_rx_start(); 
 //pinMode(led_pin, OUTPUT);
}


void loop()
{

byte buf[VW_MAX_MESSAGE_LEN];  // a buffer to store the incoming messages
byte buflen = VW_MAX_MESSAGE_LEN;       // the size of the message
int i;
lcd.clear();
lcd.print("RF_chat ON");
if( vw_get_message(buf, &buflen) )
{

  lcd.clear();
  //digitalWrite(led_pin,HIGH);
  while(1)
  {
    if(pos <= 15)
      lcd.setCursor(pos, 0);
    else
    {
      pos=0;
      lcd.clear();
    }
    for (i = 0; i < buflen; i++)
    {
      lcd.print((int)buf[i]);
    }
    delay(500);
    lcd.clear();
    pos++;
    delay(100);
    //digitalWrite(led_pin,LOW);
  }
}  
delay(2000);
}
