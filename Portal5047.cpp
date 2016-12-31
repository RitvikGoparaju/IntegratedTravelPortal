/*
#include "Portal5047.h"
#include "Airline.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Route.h"
#include "Functor.h"
*/

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Route.h"
#include "Portal5047.h"
#include "Airline.h"
#include "Flight.h"
#include "Functor.h"

void Portal5047::initRoutes(string routeInfo)
{
	string origin,destination,busOrFlight;
	float distance,duration,min,max,timeVariation;
	fstream inp(routeInfo.c_str(), fstream::in);
	while(!inp.eof())
	{
		inp>>busOrFlight;
		inp>>origin;
		inp>>destination;
		inp>>distance;
		inp>>duration;
		inp>>min;
		inp>>max;
		inp>>timeVariation;
		Route *r=new Route(busOrFlight,origin,destination,distance,duration,min,max,timeVariation);
		allRoutes.push_back(r);
	}
}

void Portal5047::addAirline(Airline *airline)
{
	allAirlines.push_back(airline);
}

void Portal5047::routeInfo(string origin, string destination,string busOrFlight, float& dist, float& duration,
	float& minPrice, float& maxPrice, float& timeVariation)
{
	int i;
	for(i=0;i<allRoutes.size();i++)
	{
		if(allRoutes[i]->getOrigin()==origin && allRoutes[i]->getDestination()==destination && allRoutes[i]->getBusOrFlight()==busOrFlight)
		{
			dist=allRoutes[i]->getDistance();
			duration=allRoutes[i]->getDuration();
			minPrice=allRoutes[i]->getMinPerKm();
			maxPrice=allRoutes[i]->getMaxPerKm();
			timeVariation=allRoutes[i]->getRelativeTime();
		}
	}
}

void Portal5047::processUserInput(string inputFileName)
{
	int lineCtr=0;
	bool b;
	std::ifstream infile(inputFileName.c_str());
	std::string line;
	while(std::getline(infile,line))
	{
		string option,sortField,sortOrder,buyOption,airlineName;
		std::istringstream iss(line);
		if(lineCtr == 0)
		{
			iss>>origin_>>destination_>>flightOrBus;
			//showFlights(origin_,destination_,Airlines, Ascending);
			//iss.str("");
			iss.clear();
		}
		else
		{
			vector<string> lineStringVector;
			while(iss)
			{
				string str;
				iss>>str;
				lineStringVector.push_back(str);
			}			
			//iss.str("");
			iss.clear();
			if(lineStringVector[0]=="sort")
			{

				sortField = lineStringVector[1];
				sortOrder = lineStringVector[2];
				cout << "Sorted Flights - Field: " + sortField + ", Order: " + sortOrder << endl;
				if(sortField=="price") {
					if(sortOrder=="ascending")
						showFlights(origin_, destination_, Price, Ascending);
					else
						showFlights(origin_, destination_, Price, Descending);
				}
				else if(sortField=="time") {
					if(sortOrder=="ascending")
						showFlights(origin_, destination_, Time, Ascending);
					else
						showFlights(origin_, destination_, Time, Descending);
				}
				else if(sortField=="duration") {
					if(sortOrder=="ascending")
						showFlights(origin_, destination_, Duration, Ascending);
					else
						showFlights(origin_, destination_, Duration, Descending);
				}
				else {
					if(sortOrder=="ascending")
						showFlights(origin_, destination_, Airlines, Ascending);
					else
						showFlights(origin_, destination_, Airlines, Descending);
				}
			}
			else if(lineStringVector[0]=="buy")
			{
				buyOption = lineStringVector[1];
				if(lineStringVector.size()==4)
					airlineName=lineStringVector[2];
				else
					airlineName="";
				if(buyOption=="cheapest")
					b=buyTicket(Cheapest, airlineName);
				else if(buyOption=="earliest")
					b=buyTicket(Earliest,airlineName);
				else if(buyOption=="fastest")
					b=buyTicket(Fastest,airlineName);
				else if(buyOption=="latest")
					b=buyTicket(Latest,airlineName);
			}
			else
			{
				origin_ = "";
				destination_ = "";
				flightOrBus="";
				origin_ = lineStringVector[0];
				destination_ = lineStringVector[1];
				flightOrBus=lineStringVector[2];
				//iss >> origin_ >> destination_;
				//showFlights(origin_,destination_,Airlines, Ascending);
			}
		}
		lineCtr++;
	}
}





void Portal5047::showFlights(string origin, string destination, SortField sortField,
	SortOrder sortOrder)
{
	int i;
	vector<Flight*> flights;
	Functor funct(sortField,sortOrder);
	flights=getAllFlights(origin,destination,flightOrBus);
	std::sort(flights.begin(),flights.end(),funct);
	cout<<"name - origin - destination - distance - departure - duration - price - Remaining Seats"<<endl;
	for(i=0;i<flights.size();i++)
	{
		cout<<flights[i]->getName()<<" "<<flights[i]->getOrigin()<<" "<<flights[i]->getDestination()<<" "
			<<flights[i]->getDistance()<<" "<<flights[i]->getDeparture()<<" "
			<<flights[i]->getDuration() << " "<<flights[i]->getAirline().getPrice(flights[i])<<" "
			<<flights[i]->numAvailableSeats()<<" "
			<<endl;
	}
}



bool Portal5047::buyTicket(BuyOption cirteria, string airline)
{
	int i;
	string buyOptionString;
	vector<Flight*>flights;
	vector<Flight*>airlineFlights;
	flights=getAllFlights(origin_,destination_,flightOrBus);
	if(airline=="")
	{
		switch(cirteria)
		{
		case Cheapest:
			{
				buyOptionString = "Cheapest";
				Functor funct1(Price,Ascending);
				std::sort(flights.begin(),flights.end(),funct1);
				break;
			};
		case Fastest:
			{
				buyOptionString = "Fastest";
				Functor funct2(Duration,Ascending);
				std::sort(flights.begin(),flights.end(),funct2);
				break;
			};
		case Earliest:
			{
				buyOptionString = "Earliest";
				Functor funct3(Time,Ascending);
				std::sort(flights.begin(),flights.end(),funct3);
				break;
			};
		case Latest:
			{
				buyOptionString = "Latest";
				Functor funct4(Time,Descending);
				std::sort(flights.begin(),flights.end(),funct4);
				break;
			};
		}
		if(flights.size()==0)
			return false;

		if ((flights[0]->getAirline()).issueTicket(flights[0])) {
			cout<<"Ticket has been issued (" << buyOptionString << ") for " << flights[0]->getName()  << endl;
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		for(i=0;i<flights.size();i++)
		{
			if(flights[i]->getAirline().getName()==airline)
				airlineFlights.push_back(flights[i]);
		}
		switch(cirteria)
		{
		case Cheapest:
			{
				buyOptionString = "Cheapest";
				Functor funct_1(Price,Ascending);
				std::sort(airlineFlights.begin(),airlineFlights.end(),funct_1);
				break;
			}
		case Fastest:
			{
				buyOptionString = "Fastest";
				Functor funct_2(Duration,Ascending);
				std::sort(airlineFlights.begin(),airlineFlights.end(),funct_2);
				break;
			}
		case Earliest:
			{
				buyOptionString = "Earliest";
				Functor funct_3(Time,Ascending);
				std::sort(airlineFlights.begin(),airlineFlights.end(),funct_3);
				break;
			}
		case Latest:
			{
				buyOptionString = "Latest";
				Functor funct_4(Time,Descending);
				std::sort(airlineFlights.begin(),airlineFlights.end(),funct_4);
				break;
			}
		}
		if(airlineFlights.size()==0)
			return false;

		if ((airlineFlights[0]->getAirline()).issueTicket(flights[0])) {
			cout<<"Ticket has been issued (" << buyOptionString << ") for " << airlineFlights[0]->getName()  << endl;
			//cout<<"Ticket has been issued for " + airlineFlights[0]->getName()  << endl;
			return true;
		}
		else {
			return false;
		}
	}
}


vector<Flight*> Portal5047::getAllFlights(string origin,string destination,string flightOrBus_)
{
	vector<Flight*> allFlights;
	vector<Flight*> allFlight;
	int i;
	for(i=0;i<allAirlines.size();i++)
	{
		allAirlines[i]->findFlights(origin,destination,allFlights);
	}
	for(i=0;i<allFlights.size();i++)
	{
		if(allFlights[i]->getAirline().getBusOrFlight()==flightOrBus_)
			allFlight.push_back(allFlights[i]);
	}
	return allFlight;
}