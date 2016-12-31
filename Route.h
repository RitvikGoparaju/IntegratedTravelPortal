#ifndef ROUTE_H
#define ROUTE_H

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Route
{
public:
	Route(string busOrFlight_,string origin_,string destination_,float distance_,float duration_,float minPerKm_,float maxPerKm_,float relativeTime_);
	string getOrigin();
	string getDestination();
	string getBusOrFlight();
	float getDuration();
	float getDistance();
	float getMinPerKm();
	float getMaxPerKm();
	float getRelativeTime();
private:
	string busOrFlight;
	string origin;
	string destination;
	float distance,duration;
	float minPerKm,maxPerKm;
	float relativeTime;
};

#endif