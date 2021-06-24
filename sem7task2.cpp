#include <iostream>
#include <string>
using namespace std;


class Time
{
private:
	int hr;
	int min;

public:
	Time() { setTime(0, 0); }
	Time(int h, int m) { setTime(h, m); }
	void setTime(int h, int m)
	{
		hr = h;
		min = m;
	}
	void getTime(int& h, int& m)
	{
		h = hr;
		m = min;
	}
	void printTime()
	{
		cout << "Время - " << hr << ":" << min << endl;
	}
	void incrementHours()
	{
		hr++;
	}
	void incrementMinutes()
	{
		min++;
	}
};


class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date() { setDate(0, 0, 0); }
	Date(int y, int m, int d) { setDate(y, m, d); }
	void setDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void getDate(int& y, int& m, int& d)
	{
		y = year;
		m = month;
		d = day;
	}
	void printDate()
	{
		cout << "Дата - " << day << "." << month << "." << year << endl;
	}
};


class Event : private Time, Date // закрытое наследование
{
private:
	string titleEvent;

public:
	Event() : Time(), Date() { setEvent(""); }
	explicit Event(Time time, Date date, string title) : Time(time), Date(date) { setEvent(title); }

	void setEvent(string title)
	{
		titleEvent = title;
	}

	void printEvent()
	{
		cout << "Название - " << titleEvent << endl;
		printDate();
		printTime();
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	Time a(20, 30);
	Date b(2020, 10, 17);
	Event c(a, b, "Kurban-Bairam");
	c.printEvent();

	system("pause");
	return 0;
}