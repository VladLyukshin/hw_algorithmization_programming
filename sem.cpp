#include <iostream>
#include <string>
using namespace std;

struct PizzaType
{
	string name;
	double diametr;
	double weight;
	string city;
};


int main()
{
	PizzaType *pizza = new PizzaType [2];
	cout << "Input information about pizza:" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Input the title: ";
		cin >> pizza[i].name;
		cout << "Input diametr of pizza: ";
		cin >> pizza[i].diametr;
		cout << "Input weight of pizza: ";
		cin >> pizza[i].weight;
		cout << "Input city: ";
		cin >> pizza[i].city;
		cin.ignore();
	}
	cout << "General information about pizza:" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << pizza[i].name << " " << pizza[i].diametr << " " << pizza[i].weight << " " << pizza[i].city << endl;
	}
	delete [] pizza;
	return 0;
}