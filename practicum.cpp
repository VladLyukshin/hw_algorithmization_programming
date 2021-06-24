#include <iostream>
#include <string>
using namespace std;


bool myDivWay1(int first, int second, int& res)
{
	if (second == 0)
	{
		res = INT_MAX;
		return false;
	}
	else
	{
		res = first / second;
		return true;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	int a, b, res;
	cout << "Введите 1е и 2е число: ";
	while (cin >> a >> b)
	{
		if (myDivWay1(a, b, res))
		{
			cout << "Неполное частное a и b равно " << res << endl;
		}
		else
		{
			cout << "Ошибка! Некорректный ввод" << endl;
		}
		cout << "Введите следующие 1е и 2е число: " << endl;
	}
	system("pause");
	return 0;
}