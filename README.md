# Integrated Travel Portal

**Overview**

This all started as an *End-Sem project* - devised by our revered professor, **Prof. T K Srikanth** - during our 3rd semester *C++ Programming* Course in *IIIT-Bangalore*. During that time (Oct/Nov-2016), I coded to include `Airline` only (the minimum requirement) to the portal. As I fell in love with this project, I, during my *semester-end holidays* (Dec-2016), extended it to include `Bus` routes & services too to the application.

**Objective**

The objective of this project is developing a sort of **Travel Portal**. Using this portal, the users can get Tickets for Airlines/Buses between the chosen *Origin* & *Destination* locations based on different criteria (like *Chepest/Earliest/Latest/etc*). The users can sort the *flights/buses* based on different **Sort Fields** (*Duration/Time/Price/etc*) and **Sor Order** (*Ascending/Descending*)

**The Requirements**

This project is to be developed under the following constraints (In fact, these ultimately prove to be not constraints but blessings for the sake of **Code Reusability/Extensibility**, etc.):

- The Given variable and method signatures of the Base Classes of *Portal*, *Airline/Busline*, *Flight/Bus* should not be changed at all
- The user should interact only with the main class

**Project Details**

There are three base classes in this project, and they are *Portal*, *Airline/Busline* & *Flight/Bus*. The Portal and the rest belong to two different categories in the sense that the derived classes of either category should be able to combine with those of the other category during implementation.

The implementational classes (derived) would be included by a Main program **TravelPortalIntegrated.cpp**. It is this program, which is accessed by outside world. Of course, the *Route*, *Airline/Busline* information would be provided in the form of text files, which would be used by different classes for initializing route and other information. Those details are explained later.

It is a wonderful project devised by our revered professor, Prof. T K Srikanth. This project, in my opinion, calls for implementing almost all OOPS concepts, like *Inheritence, Polymorphism, Abstraction, Encapsulation, etc.*

**Note**

Presently, I am using `Flight` class only for the sake of `Bus`. After all, same members (origin, destination, etc.) exist even for Bus also. Eventually, I would go for the right **semantics** to make it more user-friendly.

**How to run the application?**

- Download the zipped application from the **master** branch of this repository.
- Unzip all the folders and files. 
- Generate the executable by compiling and linking the object code. Then, execute the **TravelPortalIntegrated** program. Please keep the **txt** files intact in the folder to run the portal.

###A Sincere Appeal
Please offer your valuable **feedback** to me at **`gvkcritvik97@gmail.com`** / **`VenkataRitvik.Goparaju@iiitb.org`**

###The Class diagram
![Alt](https://ritvikgoparaju.github.io/IntegratedTravelPortalWebSite/images/classdiagram.jpg "Class Diagram")

###Another Appeal
Please also visit [**Integrated Kid Games** My Java Project] (https://github.com/RitvikGoparaju/IntegratedKidGames/ "My Java Project") Thanks!
