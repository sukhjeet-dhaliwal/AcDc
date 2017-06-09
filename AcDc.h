#ifndef AcDc_h
#define AcDc_h

#include "Arduino.h"

class AcDc
{
  public:
    
    void voltage(unsigned int _inPinV, double _VCAL);
    void current(unsigned int _inPinI, double _ICAL);

    double calcIrms(unsigned int timeOut);
		double calcVrms(unsigned int timeOut);

    //Useful value variables
    double Vrms, Irms;

  private:

    //Set Voltage and current input pins
    unsigned int inPinV;
    unsigned int inPinI;
    //Calibration coefficients
    //These need to be set in order to obtain accurate results
    double VCAL;
    double ICAL;
};

#endif
