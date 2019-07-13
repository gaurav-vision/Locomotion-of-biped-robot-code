#include <Wire.h>

#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define ServoMin 150
#define ServoMax 510

void servowrite(int servonum, int angle){
  
  int tick = map(angle,0,180,ServoMin,ServoMax);
  pwm.setPWM(servonum,0,tick);
}

void zeroset(){
  for(int i=0;i<6;i++){
    servowrite(2*i, 90);

    delay(100);
  }
}

void setup(){
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  delay(100);

  zeroset();
  delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:

}
