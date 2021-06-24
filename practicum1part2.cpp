#include <iostream>
#include <string>
using namespace std;


class badValue
{
private:
	int v1, v2;
public:
	badValue(int a = 0, int b = 0) : v1(a), v2(b) {} 
	void mesg();
};
inline void badValue::mesg()
{
	cout << "Некорректный ввод: делитель равен 0" << endl;
}


int myDivWay2(int first, int second)
{
	if (second == 0)
		throw badValue(first, second);
	return first / second;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int a, b, res;
	cout << "Введите 1е и 2е число: ";
	while (cin >> a >> b)
	{
		try
		{
			res = myDivWay2(a, b);
			cout << "Неполное частное a и b равно " << res << endl;
			cout << "Введите новый набор чисел: " << endl;
		}
		catch (badValue& bv)
		{
			bv.mesg();
			cout << "Попробуйте ввести новый набор чисел: " << endl;
			continue;
		}
	}
	system("pause");
	return 0;
}