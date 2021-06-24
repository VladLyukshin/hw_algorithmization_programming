#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Pair myPair1(1, 2);
	Pair myPair2(3, 4.123456);
	Pair myPair3, myPair4;
	List <int> a, a_new; // èíñòàíöèðóåì øàáëîí äëÿ int
	List <float> b(6.234); // èíñòàíöèðóåì øàáëîí äëÿ float
	List <double> c(1.123456); // èíñòàíöèðóåì øàáëîí äëÿ double
	List <Pair> d(myPair1);// èíñòàíöèðóåì øàáëîí äëÿ êëàññà Pair
	d.add(myPair2);
	for (int i = 1; i < 10; i++)
	{
		a.add(i);
	}
	myPair4 = myPair2; // îïåðàòîð ïðèñâàèâàíèÿ äëÿ Pair
	b.add(8);
	c.add(2.234);
	cout << "Ââåäèòå ýëåìåíò, êîòîðûé õîòèòå äîáàâèòü â ñïèñîê à: ";
	cin >> a; // ââîä çíà÷åíèå â ïåðåìåííóþ êëàññà List
	cout << "a: " << a << endl; // âûâîä ýëåìåíòà êëàññà List
	cout << "Óäàëåíèå êîðíÿ ñïèñêà:" << endl;
	a.clear_list();
	cout << "a: " << a << endl;
	cout << "Óäàëåíèå óçëà èç ñïèñêà:" << endl;
	a.remove_elem();
	cout << "a: " << a << endl;
	a.swap();
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "Ââåäèòå çíà÷åíèÿ äëÿ êëàññà Pair: ";
	cin >> myPair3;
	d.add(myPair3);
	cout << "d: " << d << endl;
	d.swap();
	cout << "d: " << d << endl;
	d.add(myPair4);
	cout << "d: " << d << endl;
	cout << "Óäàëåíèå êîðíÿ ñïèñêà:" << endl;
	d.clear_list();
	cout << "d: " << d << endl;
	a_new = a; // îïåðàòîð ïðèñâàèâàíèÿ äëÿ îäíîñâÿçíîãî ñïèñêà
	cout << "a_new: " << a_new << endl;
	system("pause");
	return 0;
}
