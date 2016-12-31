# Integrated Travel Portal
##Overview
This all started as an *End-Sem project* - devised by our revered professor, **Prof. T K Srikanth** - during our 3rd semester *C++ Programming* Course in *IIIT-Bangalore*. During that time (Oct/Nov-2016), I coded to include `Airline` only (the minimum requirement) to the portal. As I fell in love with this project, I, during my *semester-end holidays* (Dec-2016), extended it to include `Bus` routes & services too to the application.
##Objective
The objective of this project is developing a sort of **Travel Portal**. Using this portal, the users can get Tickets for Airlines/Buses between the chosen *Origin* & *Destination* locations based on different criteria (like *Chepest/Earliest/Latest/etc*). The users can sort the *flights/buses* based on different **Sort Fields** (*Duration/Time/Price/etc*) and **Sort Order** (*Ascending/Descending*)
##The Requirements/Constraints
This project is to be developed under the following constraints (In fact, these ultimately prove to be not constraints but blessings for the sake of **Code Reusability/Extensibility**, etc.):

- There are three base classes in this project, and they are *Portal*, *Airline/Busline* & *Flight/Bus*.
- The Given variable and method signatures of the Base Classes of *Portal* `Portal.h`, *Airline/Busline* `Airline.h`, *Flight/Bus* `Flight.h` should not be changed at all.
- All the implementational classes (derived) would be included in a Main program **TravelPortalIntegrated.cpp**. It is this program, which is accessed by the outside world. It means that the *userinput.txt* - about which you would learn later - file should be used by this program only.
- The *Route* information has to be initialized by the class that derives from **Portal** Class
- The *Airline/Flight, Busline/Bus* information has to be initialized by the classes which derive from those base classes. (The details about which are also explained later under the section **Input Text Files**)
- The most important requirement is that the *Portal* and *Airline/Busline, Flight/Bus* classes should be treated as belonging to **two** different categories in the sense that the derived classes of either category should be able to combine with those of the other category - developed by anyone, who follows the requirements/constraints stated here - during their actual implementation.

##Input Text Files
- Route info File Structure:

##Project Highlights
It, in my opinion, is a wonderful project for it calls for implementing almost all OOPS concepts, like *Inheritence, Polymorphism, Abstraction, Encapsulation, etc.* along with *Function Overloading* & *Operator Overloading*.

##Note
The requirements of all the base classes can be understood by reading the comments in the respective header files, viz., `Portal.h`, `Airline.h`, `Flight.h`.

Presently, I am using `Flight` class only for the sake of `Bus`. After all, same members (origin, destination, etc.) exist even for Bus also. Eventually, I would go for the right **semantics** to make it more user-friendly.

##How to run the application?

- Download the zipped application from the **master** branch of this repository.
- Unzip all the folders and files. 
- Generate the executable by compiling and linking the object code. Then, execute the **TravelPortalIntegrated** program. Please keep the **txt** files intact in the folder to run the portal.

##A Sincere Appeal
Please offer your valuable **feedback** to me at **`gvkcritvik97@gmail.com`** / **`VenkataRitvik.Goparaju@iiitb.org`**

##The Class diagram
![Alt](https://ritvikgoparaju.github.io/IntegratedTravelPortalWebSite/images/classdiagram.jpg "Class Diagram")

##Another Appeal
Please also visit [**Integrated Kid Games** My Java Project] (https://github.com/RitvikGoparaju/IntegratedKidGames/ "My Java Project") Thanks!
