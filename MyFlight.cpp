#include "MyFlight.h"
#include "Flight5047.h"

class Flight5047;

Flight5047* MyFlight::getFlight()
{
	return flight5047;
}
float MyFlight::getPrice()
{
	return price;
}

MyFlight::MyFlight(Flight5047* flight5047_,float price_)
{
	flight5047=flight5047_;
	price=price_;
}