#ifndef AIRLINE5047_1_H
#define AIRLINE5047_1_H


#include "MyFlight.h"
#include "Airline.h"
#include "Flight5047.h"

class Flight5047;
class MyFlight;
class Flight;
class Airline5047_1 : public Airline
{
public:
	Airline5047_1(Portal*);
	void init(string ifile);

	string getName(); 

	void findFlights(string origin, string destination,
				             vector<Flight *>& flights);

	float getPrice(Flight *flight);

	bool issueTicket(Flight *flight);

	int getNumSold();

	string getBusOrFlight();

	void getSalesStats(float& revenue, float& passKm);

private:
	string name;
	//vector <Flight*> allFlights;
	vector <MyFlight*> allMyFlights;
	vector <string> origin;
	vector <string> destination;
	vector <int> noOfFlights;
	int totalNumberOfTickets,noOfRemainingTickets;
	int flightNo;
};
#endif