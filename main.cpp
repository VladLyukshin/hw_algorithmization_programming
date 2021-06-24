#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Pair myPair1(1, 2);
	Pair myPair2(3, 4.123456);
	Pair myPair3, myPair4;
	List <int> a, a_new; // инстанцируем шаблон для int
	List <float> b(6.234); // инстанцируем шаблон для float
	List <double> c(1.123456); // инстанцируем шаблон для double
	List <Pair> d(myPair1);// инстанцируем шаблон для класса Pair
	d.add(myPair2);
	for (int i = 1; i < 10; i++)
	{
		a.add(i);
	}
	myPair4 = myPair2; // оператор присваивания для Pair
	b.add(8);
	c.add(2.234);
	cout << "Введите элемент, который хотите добавить в список а: ";
	cin >> a; // ввод значение в переменную класса List
	cout << "a: " << a << endl; // вывод элемента класса List
	cout << "Удаление корня списка:" << endl;
	a.clear_list();
	cout << "a: " << a << endl;
	cout << "Удаление узла из списка:" << endl;
	a.remove_elem();
	cout << "a: " << a << endl;
	a.swap();
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "Введите значения для класса Pair: ";
	cin >> myPair3;
	d.add(myPair3);
	cout << "d: " << d << endl;
	d.swap();
	cout << "d: " << d << endl;
	d.add(myPair4);
	cout << "d: " << d << endl;
	cout << "Удаление корня списка:" << endl;
	d.clear_list();
	cout << "d: " << d << endl;
	a_new = a; // оператор присваивания для односвязного списка
	cout << "a_new: " << a_new << endl;
	system("pause");
	return 0;
}