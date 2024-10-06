/*

I wrote this shit. -Collin

*/

// These constants won't change. They're used to give names to the pins used:

const int joy1y = A0;  // Analog input pin that the Y axis of the analog Joystick is attached to
const int joy1x = A1;  // Analog input pin that the X axis of the analog Joystick is attached to

// These constants control the L2930D IC

const int DriverEnable = 23;
const int DriverDirection_R_CCW = 24;
const int DriverDirection_R_CW = 25;
const int DriverDirection_L_CCW = 26;
const int DriverDirection_L_CW = 27;

int motor_R = 13;   // Digital Out Pin that controls direction of the FRONT RIGHT motor (F_R = Front right, etc)
int motor_L = 14;   // Digital Out Pin that controls direction of the FRONT LEFT motor.

int sensorValue_1y = 0;        // value read from the Y value of the joystick
int sensorValue_1x = 0;        // value read from the X value of the joystick

void setup() {

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

}

void loop() {

  // Read the analog in value:
  sensorValue_1y = analogRead(joy1y);
  //sensorValue_1x = analogRead(joy1x);

  // Declare these pins as outputs
  pinMode(DriverEnable, OUTPUT);
  pinMode(DriverDirection_R_CCW, OUTPUT);
  pinMode(DriverDirection_R_CW, OUTPUT);
  pinMode(DriverDirection_L_CCW, OUTPUT);
  pinMode(DriverDirection_L_CW, OUTPUT);
  pinMode(motor_R, OUTPUT);
  pinMode(motor_L, OUTPUT);

  // Motor is set to off by default until an input is received
  digitalWrite(motor_R, LOW);
  digitalWrite(motor_L, LOW);

  digitalWrite(DriverEnable, LOW);

  //This block defines the 'deadzone' of the Analog joystick 
  if (500 < sensorValue_1y < 550) {
    digitalWrite(DriverEnable, LOW);
   }
  else {
    digitalWrite(DriverEnable, HIGH);
    }

  //Motor Drives Forward
  if (550 <= sensorValue_1y) {
    digitalWrite(motor_R, HIGH); 
   }
  else {
    digitalWrite(motor_R, LOW);
    }

  //Motor Drives Backward
  if (sensorValue_1y <= 500) {
    digitalWrite(motor_R, HIGH);
    //digitalWrite(DriverDirection_R_CW, HIGH);
   } 
  else {
    digitalWrite(motor_R, LOW);
    //digitalWrite(DriverDirection_R_CW, LOW);
    }

  // print the results to the Serial Monitor:

  Serial.print("sensor_Y = ");

  Serial.print(sensorValue_1y);

  Serial.print("\t motor_R = ");

  Serial.println(Motor R);

  // wait 2 milliseconds before the next loop for the analog-to-digital

  // converter to settle after the last reading:

  delay(10);
}