#define DISPLAY_BRIGHTNESS  500


int D1 = 11; //PWM Display pin 1
int D2 = 10; //PWM Display pin 2
int D3 = 9; //PWM Display pin 6
int D4 = 6; //PWM Display pin 8

int A = 12; //Display pin 14
int B = 3; //Display pin 16
int C = 4; //Display pin 13
int D = 5; //Display pin 3
int E = 2; //Display pin 5 
int F = 7; //Display pin 11
int G = 8; //Display pin 15

void setup() {                
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  
  pinMode(13, OUTPUT);
}

void loop() {
  

  displayNumber(millis()/1000);

}


void displayNumber(int toDisplay) {


  long beginTime = millis();

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
      digitalWrite(D1, HIGH);
      break;
    case 2:
      digitalWrite(D2, HIGH);
      break;
    case 3:
      digitalWrite(D3, HIGH);
      break;
    case 4:
      digitalWrite(D4, HIGH);
      break;
    }

    //Turn on the right segments for this digit
    lightNumber(toDisplay % 10);
    toDisplay /= 10;

    delayMicroseconds(DISPLAY_BRIGHTNESS); //Display this digit for a fraction of a second (between 1us and 5000us, 500 is pretty good)

    //Turn off all segments
    lightNumber(10); 

    //Turn off all digits
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  }

  while( (millis() - beginTime) < 10) ; //Wait for 20ms to pass before we paint the display again
}

//Given a number, turns on those segments
//If number == 10, then turn off number


void lightNumber(int numberToDisplay) 
{
  switch (numberToDisplay)
{
  case 0:
    digitalWrite (A,  LOW);
    digitalWrite(B,  LOW);
    digitalWrite(C,  LOW);
    digitalWrite(D,  LOW);
    digitalWrite(E,  LOW);
    digitalWrite(F,  LOW);
    digitalWrite(G, HIGH);
    break;

  case 1:
    digitalWrite(A, HIGH);
    digitalWrite(B,  LOW);
    digitalWrite(C,  LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;

  case 2:
    digitalWrite(A,  LOW);
    digitalWrite(B,  LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D,  LOW);
    digitalWrite(E,  LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G,  LOW);
    break;

  case 3:
    digitalWrite(A,  LOW);
    digitalWrite(B,  LOW);
    digitalWrite(C,  LOW);
    digitalWrite(D,  LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G,  LOW);
    break;

  case 4:
    digitalWrite(A, HIGH);
    digitalWrite(B,  LOW);
    digitalWrite(C,  LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F,  LOW);
    digitalWrite(G,  LOW);
    break;

  case 5:
    digitalWrite(A,  LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C,  LOW);
    digitalWrite(D,  LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F,  LOW);
    digitalWrite(G,  LOW);
    break;

  case 6:
    digitalWrite(A,  LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C,  LOW);
    digitalWrite(D,  LOW);
    digitalWrite(E,  LOW);
    digitalWrite(F,  LOW);
    digitalWrite(G,  LOW);
    break;

  case 7:
    digitalWrite(A,  LOW);
    digitalWrite(B,  LOW);
    digitalWrite(C,  LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;

  case 8:
    digitalWrite(A,  LOW);
    digitalWrite(B,  LOW);
    digitalWrite(C,  LOW);
    digitalWrite(D,  LOW);
    digitalWrite(E,  LOW);
    digitalWrite(F,  LOW);
    digitalWrite(G,  LOW);
    break;

  case 9:
    digitalWrite(A,  LOW);
    digitalWrite(B,  LOW);
    digitalWrite(C,  LOW);
    digitalWrite(D,  LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F,  LOW);
    digitalWrite(G,  LOW);
    break;

  case 10:
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  }
}

