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
	cout << "������� 1� � 2� �����: ";
	while (cin >> a >> b)
	{
		if (myDivWay1(a, b, res))
		{
			cout << "�������� ������� a � b ����� " << res << endl;
		}
		else
		{
			cout << "������! ������������ ����" << endl;
		}
		cout << "������� ��������� 1� � 2� �����: " << endl;
	}
	system("pause");
	return 0;
}