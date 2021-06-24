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
	cout << "������������ ����: �������� ����� 0" << endl;
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
	cout << "������� 1� � 2� �����: ";
	while (cin >> a >> b)
	{
		try
		{
			res = myDivWay2(a, b);
			cout << "�������� ������� a � b ����� " << res << endl;
			cout << "������� ����� ����� �����: " << endl;
		}
		catch (badValue& bv)
		{
			bv.mesg();
			cout << "���������� ������ ����� ����� �����: " << endl;
			continue;
		}
	}
	system("pause");
	return 0;
}