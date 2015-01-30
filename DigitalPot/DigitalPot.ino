#include <Wire.h>

const int addr0 = B0000;
const int addr1 = B0001;
const int addr2 = B0110;
const int addr3 = B0111;

const int digPotAddr = B0101111; //device address "01011", A1 & A0 pulled high "11", together 7bit address



void setup()
{

  Wire.begin();
  Serial.begin(9600);
  
  delay(1000);

}

void loop()
{
	for(byte i = 0; i<256; i++)
	{
		setWiper(0,i);
		
		delay(250);
	}
  
}


boolean setWiper(byte wiper, byte position)
{
	//add checker for wiper parameter (wiper==0,1,2,3)
	if(wiper != 0 && wiper != 1 && wiper != 2 && wiper != 3)
	{
		return false;
	}
	
	Wire.beginTransmission(digPotAddr);
	
	if(wiper==0)
	{
		byte command = B00000000;
		Wire.write(command); //send completed command byte
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

void test()
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
