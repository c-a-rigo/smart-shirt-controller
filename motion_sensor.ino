
#define ADC_ref 3.52
#define zero 1.76
#define sensitivity 0.3

unsigned int value_x, value_y, value_z;
float xv, yv, zv, acceleration;
int timerId; 
float timermotion;
float valuemotion = 0;
float percentage = 0;
int stopp = 0;
int motion = 0;
int lastacceleration;
float timerstop;
float valuestop = 0;


void setup() {
Serial.begin(9600);

}



void loop() {

value_x = (analogRead(A5))-155;
value_y = (analogRead(A3))-155;
value_z = (analogRead(A4))-145;

xv=((value_x/1024.0*ADC_ref-zero)/sensitivity);

yv=((value_y/1024.0*ADC_ref-zero)/sensitivity);

zv=((value_z/1024.0*ADC_ref-zero)/sensitivity);

acceleration = sqrt ( (pow (xv, 2)) + (pow (yv, 2)) + (pow (zv, 2)));
/*Serial.print("Acceleration = ");
Serial.print(acceleration);
Serial.print(" g ");
Serial.print("\n");

*/  

if ( 0.75 > acceleration > 0.9)
  { valuemotion = millis();
    Serial.print("\n");
     Serial.print("\n");
     Serial.print("\n");
     Serial.print("IN MOTION");
     motion = 0;
     valuemotion = millis() - valuemotion;
     timermotion = timermotion + valuemotion;
   } 
   
else {
     valuestop = millis();
     Serial.print("\n");
     Serial.print("\n");
     Serial.print("STOP");
     stopp = !motion;
     motion = 1;
     valuestop = millis() - valuestop;
     timerstop = timerstop + valuestop;
     }


if (stopp == motion)
{
percentage = (timermotion/(timermotion + timerstop))*100;
Serial.print("\n");
Serial.print("tempo em movimento  ");
Serial.print (timermotion);
Serial.print("\n");
Serial.print("you were in motion ");
Serial.print(percentage);  
Serial.print(" % of the time");
Serial.print("\n");
}

}

