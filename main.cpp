#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Pair myPair1(1, 2);
	Pair myPair2(3, 4.123456);
	Pair myPair3, myPair4;
	List <int> a, a_new; // ������������ ������ ��� int
	List <float> b(6.234); // ������������ ������ ��� float
	List <double> c(1.123456); // ������������ ������ ��� double
	List <Pair> d(myPair1);// ������������ ������ ��� ������ Pair
	d.add(myPair2);
	for (int i = 1; i < 10; i++)
	{
		a.add(i);
	}
	myPair4 = myPair2; // �������� ������������ ��� Pair
	b.add(8);
	c.add(2.234);
	cout << "������� �������, ������� ������ �������� � ������ �: ";
	cin >> a; // ���� �������� � ���������� ������ List
	cout << "a: " << a << endl; // ����� �������� ������ List
	cout << "�������� ����� ������:" << endl;
	a.clear_list();
	cout << "a: " << a << endl;
	cout << "�������� ���� �� ������:" << endl;
	a.remove_elem();
	cout << "a: " << a << endl;
	a.swap();
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "������� �������� ��� ������ Pair: ";
	cin >> myPair3;
	d.add(myPair3);
	cout << "d: " << d << endl;
	d.swap();
	cout << "d: " << d << endl;
	d.add(myPair4);
	cout << "d: " << d << endl;
	cout << "�������� ����� ������:" << endl;
	d.clear_list();
	cout << "d: " << d << endl;
	a_new = a; // �������� ������������ ��� ������������ ������
	cout << "a_new: " << a_new << endl;
	system("pause");
	return 0;
}