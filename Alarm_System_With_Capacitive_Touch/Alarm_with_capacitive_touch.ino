
#define touch_output 4
int led_pin=13;
int buzzer=3;
void setup () 
{
  Serial.begin(9600);
 pinMode (13, OUTPUT);
 pinMode (3, OUTPUT);
 pinMode (4, INPUT); 
}

void loop () {
  int Val = digitalRead (touch_output);
if (Val == HIGH) {
  digitalWrite (3, HIGH);
  digitalWrite (13, HIGH);
  Serial.println("touched");
}
else {
  digitalWrite (3, LOW);
  digitalWrite (13, LOW);
  Serial.println("not touched");
}
delay (1000);
}
