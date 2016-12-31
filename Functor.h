#include "Portal.h"
#include "MyFlight.h"

class Portal;
class MyFlight;


class Functor
{
	private:
		Portal::SortOrder order;
		Portal::SortField field;
	public:
		Functor(Portal::SortField f,Portal::SortOrder o);
		Functor();
		bool operator () (Flight *f1,Flight *f2);
		void setSortField(Portal::SortField f);
		void setSortOrder(Portal::SortOrder o);

};
