//this is a pracital of interfacing Joystick with arduino uno
// you can also make a game with  the help of led etc. 

int led1=8;
int led2= 9;
int led3=10;
int led4=11;
int sensor_digital=7;           //B
int sensor_analogx=A0;    //X
int sensor_analogy=A1;       //Y

void setup() {
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(12,OUTPUT);
pinMode(7,INPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT); 

}

void loop() {
 int data1=analogRead(A0);
 int data2=analogRead(A1);
 int data3=digitalRead(7);
 Serial.print("the value of x= ");  
 Serial.print(data1);
 Serial.print("\n");
 Serial.print("the value of y=");  
 Serial.print(data2);
  Serial.print("\n");
   Serial.print("the value of B=");  
 Serial.print(data3);
  Serial.print("\n");
 delay(1000);
if (data1<500)
{
  digitalWrite(8,HIGH);
  Serial.println("white led will glow");  Serial.print("\n");
}
else
{
  digitalWrite(8,LOW);
}
if (data1>520)
{
  digitalWrite(9,HIGH);
  Serial.println("Blue led will glow");  Serial.print("\n");
}
else
{
  digitalWrite(9,LOW);
}
if (data2<500)
{
  digitalWrite(10,HIGH);
  Serial.println("Yellow led will glow");  Serial.print("\n");
}
else
{
  digitalWrite(10,LOW);
}
if (data2>520)
{
  digitalWrite(11,HIGH);
  Serial.println("white led will glow");  Serial.print("\n");
}
else
{
  digitalWrite(11,LOW);
}
}


