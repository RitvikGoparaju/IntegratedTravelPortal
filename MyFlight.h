#ifndef MYFLIGHT_H
#define MYFLIGHT_H

#include "Flight5047.h"

using namespace std;

class Flight5047;

class MyFlight
{
public:
	Flight5047* getFlight();
	float getPrice();
	MyFlight(Flight5047*,float);
private:
	Flight5047* flight5047;
	float price;
};

#endif
