

int sensor = A0;
int redled =2;
int greenled=3;
int yellowled=4;
int whiteled =5;

//int moisture_sensor =0;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
 Serial.begin(9600); 
}
void loop()
{
int data =analogRead(sensor);
Serial.println("sensor reading is =");
Serial.print(data);
Serial.println("\n");
if(data<= 300)
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
   digitalWrite(5,LOW);
  Serial.println(" full with water");
  Serial.println("\n");
  delay(1000);
  
}
if((data>300)&&(data<500)) {
    digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  Serial.println(" wet soil");
  Serial.println("\n");
  delay(1000);
}
if((data>500)&&(data<700)){
      digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  Serial.println(" humid soil");
    Serial.println("\n");
  delay(1000);
}
if((data>700)&&(data<950)){
      digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  Serial.println(" dry soil");
    Serial.println("\n");
  delay(1000);
}
if(data>=950){
     digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    Serial.println("very dry soil");
       Serial.println("\n");
  delay(1000);
}
}
