int greenled =2;
int yellowled = 3;
int buzzer =5;
int sensor =A2;
int sensorvalue=0;
void setup(){
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(A2,INPUT);
  Serial.begin(9600);
 
}
void loop()
{
  sensorvalue = analogRead(sensor);
 Serial.println("the value of sensor is");
  Serial.print(sensorvalue);
  if(sensorvalue >300){
    digitalWrite(2,HIGH);
    Serial.print("\n");
    Serial.println("green led is glowing");
    digitalWrite(3,LOW);
    digitalWrite(5,HIGH);
    Serial.println("warning:- alarm is on");
    Serial.print("\n");
  delay(1000);
  }
  else
  {
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    Serial.println("yellow led is glowing");
    digitalWrite(5,LOW);
    Serial.println("alarm is off");
    
   delay(1000);
  }
}

