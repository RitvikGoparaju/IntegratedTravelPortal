
#ifndef PORTAL5047_H
#define PORTAL5047_H

#include <string>
#include <vector>
class Route;
using namespace std;

class Airline;
class Flight;
#include "Portal.h"
#include "Flight.h"


class Portal5047: public Portal {
public:

	
	void initRoutes(string routeInfo);

	void addAirline(Airline *airline);

	void routeInfo(string origin, string destination, string busOrFlight, float& dist, float& duration,
						   float& minPrice, float& maxPrice, float& timeVariation);

	void processUserInput(string inputFileName);
	vector<Flight*> getAllFlights(string origin,string destination,string);

protected:
	void showFlights(string origin, string destination, SortField sortField = Airlines,
					 SortOrder sortOrder = Descending);

	bool buyTicket(BuyOption cirteria, string airline = "");

private:
	vector<Route*> allRoutes;
	vector<Airline*> allAirlines;
	vector<string> flightsOrBuses;
	string origin_;
	string destination_;
	string flightOrBus;
};

#endif
