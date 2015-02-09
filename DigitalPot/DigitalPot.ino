
#include <DigitalPot.h>

void setup()
{
  DigitalPot digPot();
}

void loop()
{
	
	unsigned long initial = micros();
	
	for(byte i = 0; i<255; i++)
	{
		digPot.setAll(i,i,i,i);
		delay(100);
	}
	
	Serial.print("Loop Time: ");
	Serial.println(micros()-initial);
  
}

