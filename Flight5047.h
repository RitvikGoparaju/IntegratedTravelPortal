
#ifndef FLIGHT5047_H
#define FLIGHT5047_H
#include "Flight.h"
#include "Airline.h"
#include <string>


class Airline;
using namespace std;



class Flight5047:public Flight {
public:
	
	Flight5047(string name_, string origin_, string destination_,string departure_,float duration_,int numOfAvailableSeats_,
	  float distance_,int noOfTotalSeats_,Airline* airline_);
	string getName();


	string getOrigin();
	string getDestination();
	string getDeparture();
	float getDuration();
	int numAvailableSeats();
	void setNumAvailableSeats(int);
	float getDistance();

	Airline& getAirline();
private:
	string name;
	string origin;
	string destination;
	string departure;
	float duration;
	int numOfAvailableSeats;
	float distance;
	int noOfTotalSeats;
	Airline* airline;
};

#endif