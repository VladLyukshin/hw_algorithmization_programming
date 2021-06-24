#pragma once
#include <iostream>
#include <list>
using namespace std;


class ExchangeRates;


class Observer
{
public:
	virtual void update(ExchangeRates&) = 0;
};


/////////////////////////////////////////////////////////////////////////////////////////

class ExchangeRates
{
private:
	list<Observer*> observers;
	double dollar_;
	double euro_;
	double frank_;
	double hryvnia_;

public:
	ExchangeRates() {};
	~ExchangeRates() { observers.clear(); };
	void registerObserver(Observer& tmp) 
	{
		cout << "Observer REGISTRATION" << endl;
		observers.push_back(&tmp);
	}
	void removeObserver(Observer& tmp)
	{
		cout << "Observer REMOVE" << endl;
		observers.remove(&tmp);
	}
	void notifyObserver()
	{
		cout << "NOTIFY observer" << endl;
		for (auto& Observer : observers)
		{
			cout << "UPDATE information" << endl;
			Observer->update(*this);
		}
	}
	void ExchnageRatesChanged() 
	{
		cout << "SET ExchangeRates " << endl;
		notifyObserver();
	}
	void setExchangeRates(double dollar, double euro, double frank, double hryvnia) 
	{
		dollar_ = dollar;
		euro_ = euro;
		frank_ = frank;
		hryvnia_ = hryvnia;
		ExchnageRatesChanged();
	}
	double getDollar() 
	{
		return dollar_;
	}
	double getEuro()
	{
		return euro_;
	}
	double getFrank()
	{
		return frank_;
	}
	double getHryvnia()
	{
		return hryvnia_;
	}
};


class CurrentExchangeRatesDisplay_dollar_euro: public Observer
{
private:
	ExchangeRates* exchange_rates;
	double dollar_;
	double euro_;

public:
	CurrentExchangeRatesDisplay_dollar_euro()
	{
		exchange_rates = new ExchangeRates;
	}
	~CurrentExchangeRatesDisplay_dollar_euro()
	{
		delete exchange_rates;
	}
	void subscribe(ExchangeRates& tmp) 
	{
		tmp.registerObserver(*this);
	}
	void unsubscribe(ExchangeRates& tmp) 
	{
		tmp.removeObserver(*this);
	}
	void update(ExchangeRates& ref) {
		cout << "ENTER UPDATE" << endl;
		ExchangeRates& rate = dynamic_cast<ExchangeRates&> (ref);
		dollar_ = rate.getDollar();
		euro_ = rate.getEuro();
		display();
	}
	void display() 
	{
		cout << "Current exchange rate: dollar - " << dollar_ << ", euro - " << euro_ << endl;
	}
};

class CurrentExchangeRatesDisplay_frank_hryvnia : public Observer
{
private:
	ExchangeRates* exchange_rates;
	double frank_;
	double hryvnia_;

public:
	CurrentExchangeRatesDisplay_frank_hryvnia()
	{
		exchange_rates = new ExchangeRates;
	}
	~CurrentExchangeRatesDisplay_frank_hryvnia()
	{
		delete exchange_rates;
	}
	void subscribe(ExchangeRates& tmp)
	{
		tmp.registerObserver(*this);
	}
	void unsubscribe(ExchangeRates& tmp)
	{
		tmp.removeObserver(*this);
	}
	void update(ExchangeRates& ref) {
		cout << "ENTER UPDATE" << endl;
		ExchangeRates& rate = dynamic_cast<ExchangeRates&> (ref);
		frank_ = rate.getFrank();
		hryvnia_ = rate.getHryvnia();
		display();
	}
	void display()
	{
		cout << "Current exchange rate: frank - " << frank_ << ", hryvnia - " << hryvnia_ << endl;
	}
};
