#include <iostream>
using namespace std;

class FlyBehavior
{
public:
	~FlyBehavior() { cout << "DESTRUCTOR of FlyBehavior!" << endl; }
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
	void fly()
	{
		cout << "Fly with wings!" << endl;
	}
};

class FlyNoWay : public FlyBehavior
{
public:
	void fly()
	{
		cout << "Fly no way!" << endl;
	}
};
/////////////////////////////////////////////////////////////////

class QuackBehavior
{
public:
	~QuackBehavior() { cout << "DESTRUCTOR of QuackBehavior!" << endl; }
	virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
	void quack()
	{
		cout << "Duck quacks!" << endl;
	}
};


class Squeak : public QuackBehavior
{
public:
	void quack()
	{
		cout << "Rubber duck squeaks!" << endl;
	}
};

class MuteQuack : public QuackBehavior
{
public:
	void quack()
	{
		cout << "No sound!" << endl;
	}
};

///////////////////////////////////////////////////////////


class Duck
{
private:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
public:
	Duck() {};
	~Duck() { 
		cout << "DESTRUCTOR" << endl;
		delete flyBehavior;
		delete quackBehavior;
	};
	void swim() {
		cout << "All ducks can swim!" << endl;
	}
	virtual void display() = 0;
	void performQuack() {
		quackBehavior->quack();
	}
	void performFly() {
		flyBehavior->fly();
	}
	void setFlyBehavior(FlyBehavior* fb) {
		flyBehavior = fb;
	}
	void setQuackBehavior(QuackBehavior* qb) {
		quackBehavior = qb;
	}

};

class MallardDuck : public Duck
{
public:
	MallardDuck() {
		setQuackBehavior(new Quack);
		setFlyBehavior(new FlyWithWings); 
	}
	void display()
	{
		cout << "It is a MALLARD duck!" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck() {
		setQuackBehavior(new Quack);
		setFlyBehavior(new FlyWithWings); 
	}
	void display()
	{
		cout << "It is a REDHEAD duck!" << endl;
	}
};

class RubberDuck : public Duck
{
public:
	RubberDuck() {
		setQuackBehavior(new Squeak);
		setFlyBehavior(new FlyNoWay);
	}
	void display()
	{
		cout << "It is a RUBBER duck!" << endl;
	}
};

class DecoyDuck : public Duck
{
public:
	DecoyDuck() {
		setQuackBehavior(new MuteQuack);
		setFlyBehavior(new FlyNoWay);
	}
	void display()
	{
		cout << "It is a DECOY duck!" << endl;
	}
};

////////////////////////////////////////////////////////////
template <class Type>
void myFunction(const Type& tmp)
{
	tmp->display();
	tmp->swim();
	tmp->performQuack();
	tmp->performFly();
}

//////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "rus");
	Duck* myMallardDuck = new MallardDuck;
	Duck* myRedheadDuck = new RedheadDuck;
	Duck* myRubberDuck = new RubberDuck;
	Duck* myDecoyDuck = new DecoyDuck;
	cout << "-----------------------------------------" << endl;
	myFunction(myMallardDuck);
	cout << "-----------------------------------------" << endl;
	myFunction(myRedheadDuck);
	cout << "-----------------------------------------" << endl;
	myFunction(myRubberDuck);
	cout << "-----------------------------------------" << endl;
	myFunction(myDecoyDuck);
	cout << "-----------------------------------------" << endl;
	delete myDecoyDuck;
	delete myMallardDuck;
	delete myRedheadDuck;
    delete myRubberDuck;
	system("pause");
	return 0;
}