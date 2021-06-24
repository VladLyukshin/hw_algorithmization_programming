#include <iostream>
#include <string>
using namespace std;


double calculate(double first, double second, double (*func) (double, double))
{
	return func(first, second);
}


double add(double first, double second)
{
	cout << "a + b = ";
	return first + second;
}


double sub(double first, double second)
{
	cout << "a - b = ";
	return first - second;
}


double mul(double first, double second)
{
	cout << "a * b = ";
	return first * second;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b;
	double (*func[3])(double, double) = { add, sub, mul };
	for (int i = 0; i < 3; i++)
	{
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << calculate(a, b, func[i]) << endl;
	}
	system("pause");
	return 0;
}