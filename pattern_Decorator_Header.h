#include <iostream>
#include <string>
using namespace std;



class Flight
{
protected:
	string info_;

public:
	Flight()
	{
		cout << "CONSTRUCTOR Flight" << endl;
		info_ = "Unknown flight";
	};
	virtual ~Flight() { cout << "DESTRUCTOR Flight" << endl; }
	virtual int cost() = 0;
	virtual string getInfo() { return info_; }
};


class ExtraOptions : public Flight
{
protected:
	Flight* flight_;

public:
	ExtraOptions() { cout << "CONSTRUCTOR Decorator" << endl; };
	~ExtraOptions() 
	{
		cout << "DESTRUCTOR Decorator" << endl;
		delete flight_;
	}
	virtual string getInfo() = 0;
};


////////////////////////////////////////////////////////////////////

class BusinessFlight : public Flight
{
public:
	BusinessFlight()
	{
		cout << "CONSTRUCTOR Business class" << endl;
		info_ = "Business_class_Flight";
	}
	~BusinessFlight() { cout << "DESTRUCTOR Business class" << endl; }
	int cost() { return 10000; }
};

class EconomyFlight : public Flight
{
public:
	EconomyFlight()
	{
		cout << "CONSTRUCTOR Economy class" << endl;
		info_ = "Economy_class_Flight";
	}
	~EconomyFlight() { cout << "DESTRUCTOR Economy class" << endl; }
	int cost() { return 3000; }
};

class FirstFlight : public Flight
{
public:
	FirstFlight()
	{
		cout << "CONSTRUCTOR First class" << endl;
		info_ = "First_class_Flight";
	}
	~FirstFlight() { cout << "DESTRUCTOR First class" << endl; }
	int cost() { return 20000; }
};


///////////////////////////////////////////////////


class Food : public ExtraOptions
{
public:
	Food(Flight* flight)
	{
		cout << "CONSTRUCTOR Food" << endl;
		flight_ = flight;
	}
	~Food() { cout << "DESTRUCTOR Food" << endl; }
	int cost() { return 500 + flight_->cost(); }
	string getInfo() { return flight_->getInfo() + "+Food"; }
};



class SeatSelection : public ExtraOptions
{
public:
	SeatSelection(Flight* flight)
	{
		cout << "CONSTRUCTOR Seat Selection" << endl;
		flight_ = flight;
	}
	~SeatSelection() { cout << "DESTRUCTOR Seat Selection" << endl; }
	int cost() { return 300 + flight_->cost(); }
	string getInfo() { return flight_->getInfo() + "+Seat_Selection"; }
};


class Insurance : public ExtraOptions
{
public:
	Insurance(Flight* flight)
	{
		cout << "CONSTRUCTOR Insurance" << endl;
		flight_ = flight;
	}
	~Insurance() { cout << "DESTRUCTOR Insurance" << endl; }
	int cost() { return 100 + flight_->cost(); }
	string getInfo() { return flight_->getInfo() + "+Insurance"; }
};


class ExtraBaggage : public ExtraOptions
{
public:
	ExtraBaggage(Flight* flight)
	{
		cout << "CONSTRUCTOR Extra Baggage" << endl;
		flight_ = flight;
	}
	~ExtraBaggage() { cout << "DESTRUCTOR Extra Baggage" << endl; }
	int cost() { return 1000 + flight_->cost(); }
	string getInfo() { return flight_->getInfo() + "+Extra_Baggage"; }
};

