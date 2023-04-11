#pragma once
#include <Arduino.h>

	#define PPM A0
	#define A_0 A1
	#define A_2 A2
	#define A_1 A3
	//#define SDA A4
	//#define SCL A5
	#define A_3 A6
	#define A_4 A7	
	#define ENC_L 2
	#define ENC_R 3
	#define INB_R 4
	#define PWM_1 5
	#define PWM_2 6
	#define INA_R 7
	#define INB_L 8
	#define PWM_0 9
	#define PWM_R 10
	#define PWM_L 11
	#define INA_L 12

  #define DEADBAND 10

  class RC_Control
  {
    public:
      RC_Control(uint8_t ppm, uint8_t nch);
      void listen();
      uint8_t getChannel(uint8_t i);
      void printChannels();
      
    private:
      uint8_t _ppm;
      uint8_t _nch;
      uint8_t *_ch;
      int _minRead = 600;
      int _maxRead = 1590;
  };  

  class Motor
  {
    public:
      Motor(uint8_t pwm, uint8_t dirA, uint8_t dirB);
      void move(uint8_t pwm, uint8_t dir);
      void stop();
      const uint8_t FWD = 1;
      const uint8_t BWD = !FWD;
      
    private:
      uint8_t _pwm;
      uint8_t _dirA;
      uint8_t _dirB;
  };