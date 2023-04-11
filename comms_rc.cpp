#include "NanoRC.h"

RC_Control::RC_Control(uint8_t ppm, uint8_t nch)
{
  _ppm = ppm;
  _nch = nch;
  _ch = (typeof(_ch))malloc(nch*sizeof(&_ch));

  pinMode(_ppm, INPUT);
}

void RC_Control::listen()
{  
  while(pulseIn(_ppm, HIGH, 10000)<2000){} //wait for channel 0
  
  for(uint8_t i=0; i<_nch; i++){
    uint16_t aux = pulseIn(_ppm, HIGH, 10000);
    aux = (aux>_maxRead)?_maxRead:aux;
    aux = (aux<_minRead)?_minRead:aux;
    _ch[i]= map(aux, _minRead, _maxRead, 0, 255);
  }
}

uint8_t RC_Control::getChannel(uint8_t i)
{
  return _ch[i];
}

void RC_Control::printChannels()
{ 
  uint8_t i;
  for(i=0; i<_nch-1; i++){
    Serial.print(_ch[i]);
    Serial.print(",");
  }
  Serial.println(_ch[i]);
}