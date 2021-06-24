#include <iostream>
#include <list>
#include <string>
using namespace std;

class Subject;
class Observer;
class Show;

class Subject {
public:
	virtual void registerObserver(Observer& checkist) = 0;
	virtual void removeObserver(Observer& checkist) = 0;
	virtual void notify() = 0;
	virtual void changes() = 0;
	virtual void set(string persona, string status, int amount) = 0;
};

class Observer {
public:
	virtual void update(Subject& reference) = 0;
};

class Show {
public:
	virtual void display() = 0;
};

class People : public Subject {
	list <Observer*> observers;
	string persona;
	string status;
	int amount;
public:
	People() {}
	~People() { observers.clear(); }
	void registerObserver(Observer& checkist) {
		std::cout << "Checkist started working " << std::endl;
		observers.push_back(&checkist);
	}

	void removeObserver(Observer& checkist) {
		std::cout << "Checkist stopped looking after this person " << std::endl;
		observers.remove(&checkist);
	}

	void notify() {
		std::cout << "ALARM " << std::endl;
		for (auto& Observer : observers)
		{
			std::cout << Observer << std::endl;
			std::cout << "Reference to subject: is " << this << std::endl;
			Observer->update(*this);
		}
	}

	void changes() {
		std::cout << "Set changes of persona " << std::endl;
		notify();
	}

	void set(string prs, string stat, int number) {
		persona = prs;
		status = stat;
		amount = number;
		changes();
	}

	string getName() {
		return persona;
	}

	string getStatus() {
		return status;
	}

	int getAmount() {
		return amount;
	}
};

class CurrentStatus : public Observer, public Show {
	Subject* ppl;
	int number;
	string status;
public:
	~CurrentStatus() { delete ppl; }
	void CurrentStatusDisplay() {
		ppl = new People;
	}

	void subscribe(Subject& pepl) {
		std::cout << this << std::endl;
		pepl.registerObserver(*this);
	}

	void unsubscribe(Subject& pepl) {
		pepl.removeObserver(*this);
	}

	void display() {
		std::cout << "Current status of the person is " << status << ", number of grievances equals to " << number << std::endl;
	}

	void update(Subject& pepl) {
		std::cout << "ENTER UPDATE" << std::endl;
		People& curr = dynamic_cast<People&> (pepl);
		status = curr.getStatus();
		number = curr.getAmount();
		display();
	}
};

int main() {
	People personage;
	CurrentStatus current;
	std::cout << "Observer has an adress " << &current << std::endl;
	current.subscribe(personage);
	personage.set("Oleg", "Suspicious", 6);
	current.unsubscribe(personage);
	personage.changes();
	return 0;
}