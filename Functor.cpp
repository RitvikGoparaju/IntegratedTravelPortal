#include"MyFlight.h"
#include"Flight.h"
#include"Functor.h"
#include"Portal.h"

Functor::Functor(Portal::SortField f, Portal::SortOrder o):field(f), order(o)
{
	;
}

bool Functor::operator () (Flight *f1,Flight *f2)
{
	bool t;
	bool u;
	bool bothEqual = false;
	switch(field)
	{
	case Portal::Airlines:
		{
			if ((f1->getName()).compare(f2->getName()) > 0) {
				t = true;
			}
			else if ((f1->getName()).compare(f2->getName()) < 0) {
				t = false;
			}
			else {
				t = false;
				bothEqual = true;
			}
			break;
		}
	case Portal::Duration: {
		float duration1 = f1->getDuration();
		float duration2 = f2->getDuration();

		if (duration1 > duration2) {
			t = true;
		}
		else if (duration1 < duration2) {
			t=false;
		}
		else {
			t=false;
			bothEqual = true;
		}
		break;
						   }
	case Portal::Time: {
		if ((f1->getDeparture()).compare(f2->getDeparture()) > 0) {
			t = true;
		}
		else if ((f1->getDeparture()).compare(f2->getDeparture()) < 0) {
			t = false;
		}
		else {
			t = false;
			bothEqual = true;
		}
		break;
					   }
	case Portal::Price: {
		float price1 = f1->getAirline().getPrice(f1);
		float price2 = f2->getAirline().getPrice(f2);
		if (price1 > price2) { 
			t = true;
		}
		else if (price1 < price2) {
			t = false;
		}
		else {
			t = false;
			bothEqual = true;
		}
		break;
						}
	}
	if ( (order == Portal::Descending) || (bothEqual == true) ) {
		return t;
	}
	else {
		u = (!t);
		return u;
	}
}

void Functor::setSortField(Portal::SortField f)
{
	field=f;
}

void Functor::setSortOrder(Portal::SortOrder o)
{
	order=o;
}