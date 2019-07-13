#include<Wire.h> //library for initializing

#include<Adafruit_PWMServoDriver.h> //library for 16-channel PWM servo driver shield

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  //PWM object defined

#define ServoMin 150  //tick (out of 4096) corresponding to duty cycle of minimum angle
#define ServoMax 510 // 'tick '(out of4096) corresponding to duty cycle of maximum Angle

//uint8_t num = 1;// the pin # of the servo shield to whic 0-15h the servo is connected to -->
int flag = 0; // Variable to defferentiate the first loop of steps from the rest




void servowrite(int servonum, int angle){ // function to deive servo to angle directly

  int tick = map(angle, 0, 180, ServoMin, ServoMax); //map angle to tick in duty cycle
  pwm.setPWM(servonum, 0, tick);
}

void zeroset(){ //function for setting all servos to 90 degree(zero setting)
  for(int i = 0; i<6; i++){
    servowrite(2*i, 90);
    /*calling servo write function that was defined earlier to set all servo angle to 90 degree 
     * servo connected to pins 0, 2, 4,....,10 of the servo shield for ease
     */

     delay(100);
  }
  
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at 60 hz
  delay(100);


  zeroset();  //call the zeroset function to set the servo to 90 degrees
  delay(1000);
}



void loop() {
  // put your main code here, to run repeatedly:
  for(int i=ServoMin; i<=ServoMax; i++){
    pwm.setPWM(num, 0, i);
    delay(10);
  }

  delay(2000);

  for(int i=ServoMax; i>=ServoMin; i--){
    pwm.setPWM(num, 0, i);
    delay(10);
  }

  delay(5000);
}
