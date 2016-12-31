#include "Flight5047.h"
#include "Airline.h"
string Flight5047::getName()
{
	return name;
}
string Flight5047::getOrigin()
{
	return origin;
}
string Flight5047::getDestination()
{
	return destination;
}
string Flight5047::getDeparture()
{
	return departure;
}
float Flight5047::getDuration()
{
	return duration;
}
int Flight5047::numAvailableSeats()
{
	return numOfAvailableSeats;
}
float Flight5047::getDistance()
{
	return distance;
}
Airline& Flight5047::getAirline()
{
	return *airline;
}
void Flight5047::setNumAvailableSeats(int numOfAvailableSeats_)
{
	numOfAvailableSeats=numOfAvailableSeats_;
}
Flight5047::Flight5047(string name_, string origin_, string destination_,string departure_,float duration_,int numOfAvailableSeats_,
	  float distance_,int noOfTotalSeats_,Airline* airline_)
{
	name=name_;
	origin=origin_;
	destination=destination_;
	departure=departure_;
	duration=duration_;
	numOfAvailableSeats=numOfAvailableSeats_;
	distance=distance_;
	noOfTotalSeats=noOfTotalSeats_;
	airline=airline_;
}