#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Portal5047.h"
#include "Airline5047_1.h"
#include "Busline5047_1.h"

using namespace std;

int main() {

	Portal5047 portal5047;

	//Initializing my portal with routes
	portal5047.initRoutes("routes.txt");

	//Getting airlines aligned with my portal
	Airline5047_1 airline5047_1(&portal5047);
	airline5047_1.Airline5047_1::init("airline1.txt");
	Busline5047_1 busline5047_1(&portal5047);
	busline5047_1.Busline5047_1::init("airline1.txt");
	airline5047_1.Airline5047_1::init("airline1.txt");
	portal5047.processUserInput("userInput.txt");	
	return 0;
}