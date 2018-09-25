//THIS IS 4x4 KEYPAD DOOR LOCK SYSTEM

#include <Servo.h>    // USING SERVO LIBRARY
#include <Keypad.h>     //USING KEYPAD LIBRARY YOU CAN DOWNLOAD IT ONLINE 

Servo ServoMotor;
char* password = "258";  // change the password here, just pick any 3 numbers
int position = 0;
const byte ROWS = 4;      //DEFINING  NO. OF ROWS
const byte COLS = 4;      // DEFINING NO. OF COLUMNS
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };       // CONNECT ROW(8,7,6,5) PINS TO ARDUINO PINS NO.(8,7,6,9)
byte colPins[COLS] = { 5, 4, 3, 2 };        //CONNECT COLUMN(4,3,2,1) PINS TO ARDUINO PINS NO.(5,4,3,2)
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 12;         // CONNECT AN RED LED TO THIS PIN
int GreenpinUnlock = 13;         // CONNECT AN GREEN LED TO THIS PIN 

void setup()
{
pinMode(RedpinLock, OUTPUT);
pinMode(GreenpinUnlock, OUTPUT);
ServoMotor.attach(11);
LockedPosition(true);
}

void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '#')        //TO CLOSE THE DOOR PRESS THIS KEYS
{
position = 0;
LockedPosition(true);
}
if (key == password[position])
{
position ++;
}
if (position == 3)
{
LockedPosition(false);
}
delay(100);
}
void LockedPosition(int locked)
{
if (locked)
{
digitalWrite(RedpinLock, HIGH);
digitalWrite(GreenpinUnlock, LOW);
ServoMotor.write(11);
}
else
{
digitalWrite(RedpinLock, LOW);
digitalWrite(GreenpinUnlock, HIGH);
ServoMotor.write(180);        //YOU CAN ADJUST THE DEGREE OF ROTATION OF AN SERVO MOTOR
}
}
// THANKS
