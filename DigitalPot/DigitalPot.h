#ifndef DIGITALPOT_H
#define DIGITALPOT_H
#include <Arduino.h>

class DigitalPot
{
public:
	DigitalPot();
	boolean setAll(byte position0,byte position1,byte position2,byte position3);
	boolean setWiper(byte wiper, byte position);
	boolean test();
	
private:
	const byte digPotAddr;
	const byte command0;
	const byte command1;
	const byte command2;
	const byte command3;
	};