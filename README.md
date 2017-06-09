# Arduino AcDc
## Getting Started

A sample code for measurement of Ac RMS Current and DC voltage.

```arduino
#include <AcDc.h>

#define VOLTAGE_PIN   A0
#define CURRENT_PIN   A1

AcDc measure;

void setup() {
		 measure.current(CURRENT_PIN, 108);
		 measure.voltage(VOLTAGE_PIN, 250);  
}  

void loop() {

    double rmsCurrent = measure.calcIrms(20);
		double rmsVoltage = measure.calcVrms(20);
		delay(50);
}
```

For further information, please see the attached user guide.
