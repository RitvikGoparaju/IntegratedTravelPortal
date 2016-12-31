#include"Route.h"
#include <string>



using namespace std;
Route::Route(string busOrFlight_,string origin_,string destination_,float distance_,float duration_,float minPerKm_,float maxPerKm_,float relativeTime_)
{
	busOrFlight=busOrFlight_;
	origin=origin_;
	destination=destination_;
	distance=distance_;
	duration=duration_;
	minPerKm=minPerKm_;
	maxPerKm=maxPerKm_;
	relativeTime=relativeTime_;
}
string Route::getOrigin()
{
	return origin;
}
string Route::getDestination()
{
	return destination;
}
float Route::getDuration()
{
	return duration;
}
float Route::getDistance()
{
	return distance;
}
float Route::getMinPerKm()
{
	return minPerKm;
}
float Route::getMaxPerKm()
{
	return maxPerKm;
}
float Route::getRelativeTime()
{
	return relativeTime;
}
string Route::getBusOrFlight()
{
	return busOrFlight;
}