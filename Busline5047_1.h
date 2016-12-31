#ifndef BUSLINE5047_1_H
#define BUSLINE5047_1_H


#include "MyFlight.h"
#include "Airline.h"
#include "Flight5047.h"

class Flight5047;
class MyFlight;
class Flight;
class Busline5047_1 : public Airline
{
public:
	Busline5047_1(Portal*);
	void init(string ifile);

	string getBusOrFlight();
	string getName(); 

	void findFlights(string origin, string destination,
				             vector<Flight *>& buses);

	float getPrice(Flight *bus);

	bool issueTicket(Flight *bus);

	int getNumSold();

	void getSalesStats(float& revenue, float& passKm);

private:
	string name;
	//vector <Flight*> allFlights;
	vector <MyFlight*> allMyBuses;
	vector <string> origin;
	vector <string> destination;
	vector <int> noOfBuses;
	int totalNumberOfTickets,noOfRemainingTickets;
	int busNo;
};
#endif