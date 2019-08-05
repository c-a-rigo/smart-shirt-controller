
#define ADC_ref 3.52
#define zero 1.76
#define sensitivity 0.3

long timenow = 0;
int turninterval = 3567;
long previoustime = 0;

unsigned int value_y;
float yv;
int i = 0;
int j = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
unsigned long timenow = millis();

value_y = (analogRead(A3))-155;

yv=((value_y/1024.0*ADC_ref-zero)/sensitivity);

if (timenow - previoustime > turninterval){
  if (yv > 0.8)
     { previoustime = timenow;
     
     Serial.print("\n");
     Serial.print("\n");
     i++;
     Serial.print("\n");
     Serial.print(i  );
     Serial.print("TURN RIGHT DETECTED");
     Serial.print("\n");
     Serial.print("\n");
     Serial.print("\n");
     } 
 }

if (timenow - previoustime > turninterval){
  if (yv < -0.8)
     { previoustime = timenow;
     Serial.print("\n");
     Serial.print("\n");
     j++;
     Serial.print("\n");
     Serial.print(j  );
     Serial.print("TURN LEFT DETECTED");
     Serial.print("\n");
     Serial.print("\n");
     Serial.print("\n");
     } 
 }
}

