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
  //put your main code here to run repeatedly:
  /*
   * step - 1 :
   * left ankle -90 -->45
   * right ankle -90-->70
   */
  for(int i=0; i<4; i++){
    servowrite(0,90-15*i);
    delay(100);
    if (i<3){
      servowrite(10, 90-10*i);
      delay(100);
    }
  }


  if(flag=0){
    /* step - 2:
     *  left hip -90-->105
     *  left thigh -90-->105
     *  right hip -90-->105
     *  right thigh -90 --> 105
     */

     for(int i=0; i<4; i++){
      servowrite(4,90+5*i);
      servowrite(2,90+5*i);
      servowrite(6,90+5*i);
      servowrite(8,90+5*i);
      delay(100);
     }
  }
  else{
    /*step -2A:
     * Left Hip -75-->105
     * Left thigh -75-->105
     * Right Hip -75-->105
     * Right Thigh -75-->105
     */
     for(int i=0; i<7; i++){
      servowrite(4, 75+5*i);
      servowrite(2, 75+5*i);
      servowrite(6, 75+5*i);
      servowrite(8, 75+5*i);
      delay(100);
     }
  }


  /*step - 3:
   * Left Ankle -45-->90
   * Right Ankle -70-->90
   * 
   */
  for (int i=0; i<4; i++){
    servowrite(0,45+15*i);
    delay(100);
    if(i<3){
      servowrite(10, 70+10*i);
      delay(100);
    }
  }


  /*Step - 4:
   * Right Ankle -90-->135
   * Left Ankle -90-->110
   * 
   */

   for(int i=0; i<4; i++){
    servowrite(10, 90+15*i);
    delay(100);
    if(i<3){
      servowrite(0, 90+10*i);
      delay(100);
    }
   }

   /*step -5
    * Left hip -105-->75
    * Left Thigh -105-->75
    * Right Hip -105-->75
    * Right thigh -105-->75
    */
    for(int i=0; i<7; i++){
      servowrite(4, 105-5*i);
      servowrite(2, 105-5*i);
      servowrite(6, 105-5*i);
      servowrite(8, 105-5*i);
      delay(100);
    }

    /*step - 6:
     * Right Ankle -135-->90
     * Left Ankle -110-->90
     */
     for(int i=0; i<4; i++){
      servowrite(10, 135-15*i);
      delay(100);
      if(i<3){
        servowrite(0, 110-10*i);
        delay(100);
      }
     }

     flag++; //After cycle 1 changes the gait to initiate step 2 from servo positioned at 75 degree
}
