# Integrated Travel Portal
##Overview
This all started as the *End-Sem project* - devised by our revered professor, **Prof. T K Srikanth** - during our 3rd semester *C++ Programming* Course in *IIIT-Bangalore*. During that time (Oct/Nov-2016), I coded to include `Airline` only (the minimum requirement) to the portal. As I fell in love with this project, I, during my *semester-end holidays* (Dec-2016), extended it to include `Bus` routes & services too to the application.
##Objective
The objective of this project is developing a sort of **Travel Portal**. Using this portal, the users can get Tickets for Airlines/Buses between the chosen *Origin* & *Destination* locations based on different criteria (like *Chepest/Earliest/Latest/etc*). The users can sort the *flights/buses* based on different **Sort Fields** (*Duration/Time/Price/etc*) and **Sort Order** (*Ascending/Descending*)
##The Requirements/Constraints
This project is to be developed under the following constraints (In fact, these ultimately prove to be not constraints but blessings for the sake of **Code Reusability/Extensibility**, etc.):

- There are three base classes in this project, and they are *Portal*, *Airline/Busline* & *Flight/Bus*.
- The Given variable and method signatures of the Base Classes of *Portal* `Portal.h`, *Airline/Busline* `Airline.h`, *Flight/Bus* `Flight.h` should not be changed at all.
- All the implementational classes (derived) would be included in a Main program **TravelPortalIntegrated.cpp**. It is this program, which is accessed by the outside world. 
- The class that derives *Portal* should read *userinput.txt* - about which you would learn later - file for processing the sort/buy options submitted by the users.
- The *Route* information has to be initialized by the class that derives from **Portal** Class
- The *Airline/Flight, Busline/Bus* information has to be initialized by the classes which derive from those base classes. (The details about which are also explained later under the section **Input Text Files**)
- The most important requirement is that the *Portal* and *Airline/Busline, Flight/Bus* classes should be treated as belonging to **two** different categories in the sense that the derived classes of either category should be able to combine with those of the other category - developed by anyone, who follows the requirements/constraints stated here - during their actual implementation.

##Input Text Files & Their Structures
**Routes**

String (*Flight/Bus*) - String (*Origin*) - String (*Destination*) - Number (*Distance*) - Number (*Duration, mins*) - Number (*Minimum Rate/km*) - Number (*Maximum Rate/km*) - Number (*Duration Time variation, mins.*)

*Example*:<br>Flight Bangalore Hyderabad 500 70 6.0 9.0 7<br>Bus Bangalore Mumbai 1000 416 2.16 3.12 40

**Airline/Busline**

First line: Number (*Total Number of Tickets available per Airline/Busline per day*)<br>Remaining lines: String (*Origin*) - String (*Destination*) - Number (*Number of Flights per day*)<br>

*Example*:<br>30<br>Bangalore Mumbai 2<br>Jaipur Delhi 7

**User Input**

First line: String (*Origin*) - String (*Destination*) - String (*Flight/Bus*)<br>
Next Line Onwards: Either Sort/Buy as shown below:<br>
*For Sorting*: String (sort) - String (*Sort Field* **price/duration/time**, etc.) - String (*Sort Order* **Ascending/Descending**)<br>
*For Buying*: String (buy) - String (*Buy Option* **Cheapest/Earliest**, etc.) - (Optional) String (*Airline/Busline Name*)

*Example*:<br>
Jaipur Delhi Flight<br>
sort price ascending<br>
sort time descending<br>
buy cheapest<br>
buy earliest Airline5047_1<br>
sort price ascending<br>
Bangalore Mumbai Bus<br>
sort price descending<br>
sort duration ascending<br>
buy earliest<br>
buy cheapest Busline5047_1<br>
sort price descending<br>

**Note**<br>The *Airline/Busline*, *Flight/Bus* details can be initialized randomly within the constraints of *Routes* info presented above<br>
##Project Highlights
It, in my opinion, is a wonderful project for it calls for implementing almost all OOPS concepts, like *Inheritence, Polymorphism, Abstraction, Encapsulation, etc.* along with *Function Overloading* & *Operator Overloading* (*Functors* too).

##Note
The requirements of all the base classes can be understood by reading the comments in the respective header files, viz., `Portal.h`, `Airline.h`, `Flight.h`.

Presently, I am using `Flight` class only for the sake of both `Flight` & `Bus` and `Airline` only for the sake of both `Airline` & `Busline`. After all, same members (origin, destination, etc.) exist even for Bus also. Eventually, I would go for the right **semantics** to make it more user-friendly.

##How to run the application?

- Download the zipped application from the **master** branch of this repository.
- Unzip all the folders and files. 
- Generate the executable by compiling and linking the object code. Then, execute the **TravelPortalIntegrated** program. Please keep the **txt** files intact in the folder to run the portal.

##A Sincere Appeal
Please offer your valuable **feedback** to me at **`VenkataRitvik.Goparaju@iiitb.org`** / **`gvkcritvik97@gmail.com`**

##The Class diagram
![Alt](https://ritvikgoparaju.github.io/IntegratedTravelPortalWebSite/images/classdiagram.jpg "Class Diagram")

##Another Appeal
Please also visit [**Integrated Kid Games** My Java Project] (https://github.com/RitvikGoparaju/IntegratedKidGames/ "My Java Project") Thanks!

##Gratitude
My sincere thanks to **Prof. TK Srikanth** for the wonderful guidance, support and encouragement.
