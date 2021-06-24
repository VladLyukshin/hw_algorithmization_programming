#include<iostream>
using namespace std;

template<class T>
class Binary_Operation
{
public:
	Binary_Operation() { cout << "Constructor of binary operation" << endl; }
	virtual T operation(T first, T second) { return operation(first, second); }
	virtual ~Binary_Operation() {}
};

template<class T>
class Multiplication : public Binary_Operation<T>
{
public:
	Multiplication() { cout << "Constructor of multiplication" << endl; }
	T operation(T first, T second)
	{
		return first * second;
	}
};

template<class T>
class Exponentiation : public Binary_Operation<T>
{
public:
	Exponentiation() { cout << "Constructor of exponentiation" << endl; }
	T operation(T first, T second)
	{
		return pow(first, second);
	}
};

template<class T>
class Addition : public Binary_Operation<T>
{
public:
	Addition() { cout << "Constructor of addition" << endl; }
	T operation(T first, T second)
	{
		return first + second;
	}
};


int main()
{
	Binary_Operation<int>* arr[3];
	arr[0] = new Addition<int>;
	arr[1] = new Multiplication<int>;
	arr[2] = new Exponentiation<int>;
	cout << "Sum: " << arr[0]->operation(1, 2) << endl;
	cout << "Multiplication:" << arr[1]->operation(2, 2) << endl;
	cout << "Exp: " << arr[2]->operation(2, 5) << endl;
	delete[] *arr;
	return 0;
}