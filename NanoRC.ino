#include "NanoRC.h"

Motor motorL(PWM_L, INA_L, INB_L);
Motor motorR(PWM_R, INA_R, INB_R);

RC_Control rc(PPM, 6);
const uint8_t ch_vel = 1; // CH3: speed
const uint8_t ch_dir = 3; // CH4: direction
const uint8_t ch_swA = 4; // CH5: motor enable

const float k = 1;

void setup() {
  Serial.begin(9600);
  pinMode(PPM, INPUT);
}

void loop() {
  rc.listen();
  if(rc.getChannel(ch_swA)>=250)
  {
    float dir = rc.getChannel(ch_dir);
    float vel = rc.getChannel(ch_vel);
    float velR = vel + k*(dir-127.5);
    float velL = vel - k*(dir-127.5);

    velR = (velR<0)?0:velR;
    velR = (velR>255)?255:velR;
    velR = (abs(velR-127.5)<DEADBAND)?0:velR;
    
    velL = (velL<0)?0:velL;
    velL = (velL>255)?255:velL;
    velL = (abs(velL-127.5)<DEADBAND)?0:velL;
    
    if(velR<127.5)
      motorR.move(2*(127.5-abs(velR)), motorR.BWD);
    else
      motorR.move(2*(abs(velR)-127.5), motorR.FWD);
    
    if(velL<127.5)
      motorL.move(2*(127.5-abs(velL)), motorL.BWD);
    else
      motorL.move(2*(abs(velL)-127.5), motorL.FWD);
  }
  else
  {
    motorR.stop();
    motorL.stop();
  }
}
