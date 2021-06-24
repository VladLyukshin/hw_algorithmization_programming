#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Flight* flight_eco = new EconomyFlight;
	Flight* flight_business = new BusinessFlight;
	Flight* flight_first = new FirstFlight;
	flight_eco = new Food(flight_eco);
	flight_eco = new ExtraBaggage(flight_eco);
	flight_eco = new SeatSelection(flight_eco);
	flight_eco = new Insurance(flight_eco);
	cout << flight_eco->getInfo() << ", total cost - " << flight_eco->cost() << endl;
	delete flight_eco;
	flight_business = new ExtraBaggage(flight_business);
	flight_business = new Insurance(flight_business);
	cout << flight_business->getInfo() << ", total cost - " << flight_business->cost() << endl;
	delete flight_business;
	flight_first = new Insurance(flight_first);
	cout << flight_first->getInfo() << ", total cost - " << flight_first->cost() << endl;
	delete flight_first;
	system("pause");
	return 0;
}