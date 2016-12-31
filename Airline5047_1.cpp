#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Airline5047_1.h"
#include "Flight5047.h"
#include "Flight.h"
#include "Portal.h"
#include "MyFlight.h"

using namespace std;

class Flight5047;
class Portal;
class MyFlight;

Airline5047_1::Airline5047_1(Portal* pl): Airline(pl)
{
	this->getPortal()->addAirline(this);
	name="Airline5047_1";
	flightNo=10;
}

void Airline5047_1::init(string ifile)
{
	float dist,duration,minPrice,maxPrice, timeVariation;
	string starting,ending;
	int numberOfFlights,i,j,totalFlightsPerAirline=0;
	int eachFlightTickets,firstFlightTickets;
	fstream inp(ifile.c_str(), fstream::in);
	inp>>totalNumberOfTickets;
	noOfRemainingTickets=totalNumberOfTickets;
	while(!inp.eof())
	{
		inp>>starting;
		inp>>ending;
		inp>>numberOfFlights;
		origin.push_back(starting);
		destination.push_back(ending);
		noOfFlights.push_back(numberOfFlights);
		totalFlightsPerAirline+=numberOfFlights;
	}
	eachFlightTickets=totalNumberOfTickets/totalFlightsPerAirline;
	firstFlightTickets=eachFlightTickets + (totalNumberOfTickets%totalFlightsPerAirline);
	for(i=0;i<origin.size();i++)
	{
		this->Airline::getPortal()->routeInfo(origin[i], destination[i], "Flight", dist, duration,minPrice,maxPrice, timeVariation);
		for(j=0;j<noOfFlights[i];j++)
		{
			/*string getOrigin();
			string getDestination();
			float getDuration();
			float getDistance();
			float getMinPerKm();
			float getMaxPerKm();
			float getRelativeTime();*/
			//string FlightPortionNo=(string)flightNo;
			stringstream ss;
			ss << flightNo;
			string flightPortionNo = ss.str();
			stringstream ss1;
			ss1 << i;
			stringstream ss2;
			ss2 << j;
			Flight5047* f;
			if(i==0 &&j==0)
			{
				/*(string name_, string origin_, string destination_,string departure_,float duration_,int numOfAvailableSeats_,
				float distance_,int noOfTotalSeats_,Airline& airline_)*/
				//routeInfo(origin, destination,dist,duration,minPrice,maxPrice, timeVariation);
				f= new Flight5047(name+flightPortionNo,origin[i],destination[i],"1"+ss1.str()+"2"+ss2.str(),duration-timeVariation+i+j,
					firstFlightTickets,dist,firstFlightTickets,this);
			}
			else
			{
				f= new Flight5047(name+flightPortionNo,origin[i],destination[i],"1"+ss1.str()+"2"+ss2.str(),duration-timeVariation+i+j,
					eachFlightTickets,dist,firstFlightTickets,this);
			}
			float price=((minPrice+maxPrice)/2.0)*dist+i+j;
			MyFlight *mF=new MyFlight(f,price);
			allMyFlights.push_back(mF);
			flightNo++;
		}
	}


}

string Airline5047_1::getName()
{
	return name;
}

void Airline5047_1::findFlights(string origin, string destination,vector<Flight *>& flights)
{
	int i;
	for(i=0;i<allMyFlights.size();i++)
	{
		if((allMyFlights[i]->getFlight())->getOrigin()==origin && (allMyFlights[i]->getFlight())->getDestination()==destination)
		{
			flights.push_back(allMyFlights[i]->getFlight());
		}
	}
}

float Airline5047_1::getPrice(Flight *flight)
{
	int i;
	for(i=0;i<allMyFlights.size();i++)
	{
		//if((allMyFlights[i]->getFlight())->getName()==flight->getName())
		if(dynamic_cast<Flight*>(allMyFlights[i]->getFlight())==flight)
		{
			return allMyFlights[i]->getPrice();
		}
	}
}

bool Airline5047_1::issueTicket(Flight *flight)
{
	int i;
	for(i=0;i<allMyFlights.size();i++)
	{
		//if((allMyFlights[i]->getFlight())->getName()==flight->getName
		if(allMyFlights[i]->getFlight() == flight)
		{
			Flight5047* f5047 = dynamic_cast<Flight5047*>(flight);
			if(f5047->numAvailableSeats()>0)
			{
				f5047->setNumAvailableSeats(f5047->numAvailableSeats()-1);
				totalNumberOfTickets=totalNumberOfTickets-1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}


int Airline5047_1::getNumSold()
{
	return totalNumberOfTickets-noOfRemainingTickets;
}

void Airline5047_1::getSalesStats(float& revenue, float& passKm)
{
	revenue=0;
	passKm=0;
	int i;
	for(i=0;i<allMyFlights.size();i++)
	{
		revenue=revenue+allMyFlights[i]->getPrice();
		passKm=passKm+(allMyFlights[i]->getFlight())->getDistance();
	}
}

string Airline5047_1::getBusOrFlight()
{
	return "Flight";
}