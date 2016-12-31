# Integrated Travel Portal

**Overview**

This all started as an *End-Sem project* during my 3rd semester *C++ Programming* Course in *IIIT-Bangalore*. I then coded to include `Airline` to the portal. As I fell in love with this project, I, during the *semester-end holidays*, extended it to include `Bus` routes & services too to the application.

This project is for developing a sort of **Travel Portal**. Using this portal, the users can get Tickets for Airlines/Buses between the chosen *Origin* & *Destination* locations.

**Project Details**

There are three base classes in this project, and they are *Portal*, *Airline/Busline* & *Flight/Bus*. The Portal and the rest belong to two different categories in the sense that the derived classes of either category should be able to combine with those of the other category during implementation.

The implementational classes (derived) would be included by a Main program **TravelPortalIntegrated.cpp**. It is this program, which is accessed by outside world. Of course, the *Route*, *Airline/Busline* information would be provided in the form of text files, which would be used by different classes for initializing route and other information. Those details are explained later.

It is a wonderful project devised by our revered professor, Sri T K Srikanth. This project, in my opinion, calls for implementing almost all OOPS concepts, like *Inheritence, Polymorphism, Abstraction, Encapsulation, etc.*

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
