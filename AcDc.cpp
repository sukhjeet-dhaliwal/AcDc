#include "AcDc.h"
#include "Arduino.h"



//--------------------------------------------------------------------------------------
// Sets the pins to be used for voltage and current sensors
//--------------------------------------------------------------------------------------
void AcDc::voltage(unsigned int _inPinV, double _VCAL)
{
  inPinV = _inPinV;
  VCAL = _VCAL;
}

void AcDc::current(unsigned int _inPinI, double _ICAL)
{
  inPinI = _inPinI;
  ICAL = _ICAL;
}

double AcDc::calcIrms(unsigned int timeOut){
  int readValue;
  int maxValue = 0;
  uint32_t start_time = millis();
  while ((millis() - start_time) < timeOut)
  {
    readValue = analogRead(inPinI);
    // see if you have a new maxValue
    if (readValue > maxValue)
    {
      /*record the maximum sensor value*/
      maxValue = readValue;
    }
  }
  Irms = ((((maxValue * 5.0) / 1023.0) * 0.707) * 1000) / ICAL;
	return Irms;
}

double AcDc::calcVrms(unsigned int timeOut){
  int readValue;
  int maxValue = 0;
  uint32_t start_time = millis();
  while ((millis() - start_time) < timeOut)
  {
    readValue = analogRead(inPinV);
    // see if you have a new maxValue
    if (readValue > maxValue)
    {
      /*record the maximum sensor value*/
      maxValue = readValue;
    }
  }
  Vrms = maxValue * (VCAL / 1023.0);
	return Vrms;
}

