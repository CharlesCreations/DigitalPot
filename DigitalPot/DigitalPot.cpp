#include <Arduino.h>
#include <Wire.h>
#include <DigitalPot.h>

const byte digPotAddr = B0101111; //device address "01011", A1 & A0 pulled high "11", together 7bit address

//Command bytes for each of the digital potentiometers
const byte command0 = B00000000;
const byte command1 = B00010000;
const byte command2 = B01100000;
const byte command3 = B01110000;



DigitalPot::DigitalPot()
{
	Wire.begin();
}

//average of 232us execution time

boolean DigitalPot::setAll(byte position0, byte position1, byte position2, byte position3)
{
	Wire.beginTransmission(digPotAddr);
	
	Wire.write(command0);
	Wire.write(position0);
	Wire.write(command1);
	Wire.write(position1);
	Wire.write(command2);
	Wire.write(position2);
	Wire.write(command3);
	Wire.write(position3);
	
	if(Wire.endTransmission()==0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//average of 332uS execution time

boolean DigitalPot::setWiper(byte wiper, byte position)
{
	//add checker for wiper parameter (wiper==0,1,2,3)
	if(wiper != 0 && wiper != 1 && wiper != 2 && wiper != 3)
	{
		return false;
	}
	
	Wire.beginTransmission(digPotAddr);
	
	if(wiper==0)
	{
		
		Wire.write(command0); //send completed command byte
		Wire.write(position); //send position
		if(Wire.endTransmission()==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(wiper==1)
	{
		Wire.write(command1); //send completed command byte
		Wire.write(position); //send position
		if(Wire.endTransmission()==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(wiper==2)
	{
		Wire.write(command2); //send completed command byte
		Wire.write(position); //send position
		if(Wire.endTransmission()==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(wiper==3)
	{
		Wire.write(command3); //send completed command byte
		Wire.write(position); //send position
		if(Wire.endTransmission()==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void DigitalPot::test()
{
	//with P0B connected to VCC, P0A connected to GND, P0W will alternate between VCC and GND
	Wire.beginTransmission(digPotAddr);
	Wire.write(B00000000);
	Wire.write(B00000000);
	Serial.println(Wire.endTransmission());
	
	delay(2000);
	
	Wire.beginTransmission(digPotAddr);
	Wire.write(B00000001);
	Wire.write(B11111111);
	Serial.println(Wire.endTransmission());
	
	delay(2000);
}