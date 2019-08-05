
// variables will not change:
const int ledPinRight =  13;  
const int ledPinLeft = 12;
const int buttonRight = 11;
const int buttonLeft = 10;
const int pinAccX = 0;
const int pinAccY = 1;
const int pinAccZ = 2;

// Variables will change:
int ledStateLeft = LOW;
int ledStateRight = LOW;             
long previousMillis = 0;
long previousButton = -500;
boolean right = false;
boolean left = false;
boolean all = false;
//int lastButtonRightState = LOW;
//int lastButtonLeftState = LOW;
//int buttonStateRight;
//int buttonStateLeft;
//int readingLeft;
//int readingRight;
//long lastDebounceTimeRight = 0;
//long lastDebounceTimeLeft = 0;
//long debounceDelay = 50;
int accX;
int accy;
int accz;


long interval = 1000;      // interval at which to blink (milliseconds)

int leftButtonState;
int leftLastButtonState = LOW;
long leftLastDebounceTime = 0;
long debounceDelay = 50;
boolean checkButtonLeft(){
  int leftReading = digitalRead(buttonLeft);
  
  if(leftReading != leftLastButtonState){
  leftLastDebounceTime = millis();
  
  }
  
   if ((millis() - leftLastDebounceTime) > debounceDelay) {

    if (leftReading != leftButtonState) {
      leftButtonState = leftReading;

      if (leftButtonState == HIGH) {
        if(left == false){
        
          return true;
          
        }else{
        return false;
        }
      }
    }
  }
  return false;
  
}


/*void checkButton(){
  
  buttonStateRight = digitalRead(buttonRight);
  buttonStateLeft = digitalRead(buttonLeft);
  
  if(buttonStateRight != lastButtonRightState){
  lastDebounceTimeRight = millis();
  }
  
   if(buttonStateLeft != lastButtonLeftState){
  lastDebounceTimeLeft = millis();
  }
  
  unsigned long currentMillis = millis();
  
  if(buttonStateRight == HIGH && (millis() - lastDebounceTimeRight) > debounceDelay){
    
    if((currentMillis - previousButton) < 700 && !all && (currentMillis - previousButton) > 30){
    
      all = true;
      right = false;
      left = false;
      delay(1);
      
    } else if((currentMillis - previousButton) < 700 && all){
    
      all = false;
      right = false;
      left = false;
      delay(1);
      
    } else if(right){
      all = false;
      right = false;
      left = false;
      delay(1);
    } else{
      all = false;
      right = true;
      left = false;
      delay(1);
    }
    
    previousButton = currentMillis;
    
  } else if(buttonStateLeft == HIGH && left &&  (millis() - lastDebounceTimeLeft) > debounceDelay){
    if(buttonStateLeft != readingLeft){
      readingLeft = buttonStateLeft;
      if(readingLeft == HIGH){
    right = false;
    all = false;
    left = false;
    delay(1);
      }}
    
  } else if(buttonStateLeft == HIGH &&  (millis() - lastDebounceTimeLeft) > debounceDelay){
    if(buttonStateLeft != readingLeft){
      readingLeft = buttonStateLeft;
      if(readingLeft == HIGH){
    right = false;
    all = false;
    left = true;
    delay(1);
      }
    }
  }
  delay(1);
}*/

void blinkRight(){
 unsigned long currentMillis = millis();
 ledStateLeft = LOW;
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;   

  if(ledStateRight == LOW){
    ledStateRight = HIGH;
  } else{
    ledStateRight = HIGH;
  }
  
  digitalWrite(ledPinRight, ledStateRight);
  digitalWrite(ledPinLeft, ledStateLeft);

  }

}

void blinkLeft(){
 unsigned long currentMillis = millis();
 ledStateRight = LOW;
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;   

  if(ledStateLeft == LOW){
    ledStateLeft = HIGH;
  } else{
    ledStateLeft = HIGH;
  }
  
  digitalWrite(ledPinLeft, ledStateLeft);
  digitalWrite(ledPinRight, ledStateRight);
  }

}

void blinkAll(){
  
 unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;   

  if(ledStateRight == LOW){
    ledStateRight = HIGH;
    ledStateLeft = HIGH;
  } else {
    ledStateRight = LOW;
    ledStateLeft = LOW;
  }
  
  digitalWrite(ledPinRight, ledStateRight);
  digitalWrite(ledPinLeft, ledStateLeft);

  }
 
}

void turnOffAll(){
  
  ledStateRight = LOW;
  ledStateLeft = LOW;
 
  digitalWrite(ledPinRight, ledStateRight);
  digitalWrite(ledPinLeft, ledStateLeft);


}



void setup() {
  pinMode(ledPinRight, OUTPUT);
  pinMode(ledPinLeft, OUTPUT); 
  pinMode(buttonRight, INPUT);
  pinMode(buttonLeft, INPUT);  
  
  digitalWrite(ledPinRight, ledStateRight);
  digitalWrite(ledPinLeft, ledStateLeft);
}



void loop()
{
  
  //checkButton();
  
  left = checkButtonLeft();
  
 if(all){
   blinkAll();
 } 
 
 else if(right){
   blinkRight();
 } 

 else if(left){
   blinkLeft();
 }

 else{
   turnOffAll();
 }

}

