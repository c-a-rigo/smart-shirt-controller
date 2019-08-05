//from electronicsblog.net/

#define ADC_ref 3.52
#define zero 1.76
#define sensitivity 0.3

unsigned int value_x, value_y, value_z;
float xv, yv, zv, acceleration;
float angle_x, angle_y, angle_z;

void setup() {
Serial.begin(9600);
}

void loop() {

value_x = (analogRead(A5))-155;
value_y = (analogRead(A3))-155;
value_z = (analogRead(A4))-145;

xv=((value_x/1024.0*ADC_ref-zero)/sensitivity);
Serial.print ("x = ");
Serial.print (xv);
Serial.print(" g    ");

yv=((value_y/1024.0*ADC_ref-zero)/sensitivity);
Serial.print ("y = ");
Serial.print (yv);
Serial.print(" g    ");

zv=((value_z/1024.0*ADC_ref-zero)/sensitivity);
Serial.print ("z = ");
Serial.print (zv);
Serial.print(" g    ");

Serial.print("\n");


acceleration = sqrt ( (pow (xv, 2)) + (pow (yv, 2)) + (pow (zv, 2)));
Serial.print("Acceleration = ");
Serial.print(acceleration);
Serial.print(" g ");
Serial.print("\n");

if (acceleration > 3.5)
   { Serial.print("\n");
     Serial.print("\n");
     Serial.print("\n");
     Serial.print("FALL DETECTED!!!!!!");
     Serial.print("\n");
     Serial.print("\n");
     Serial.print("\n");
     Serial.print("\n");}
 

/*

Serial.print("\n");

Serial.print("Rotation ");

Serial.print("x= ");

angle_x =atan2(-yv,-zv)*57.2957795+180;

Serial.print(angle_x);
Serial.print(" deg");
Serial.print(" ");

Serial.print("y= ");

angle_y =atan2(-xv,-zv)*57.2957795+180;

Serial.print(angle_y);
Serial.print(" deg");
Serial.print(" ");

Serial.print("z= ");

angle_z =atan2(-yv,-xv)*57.2957795+180;

Serial.print(angle_z);
Serial.print(" deg");
Serial.print("\n"); */

}

