#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


class Shape
{
protected:
	char* name_ = new char[10];

public:
	Shape()
	{
		strcpy(name_, "Shape"); // устанавливаем название фигуры
	}

	virtual double Area() // виртуальная функция
	{
		return Area();
	}

	virtual Shape& operator=(const Shape& shape) // оператор присваивания
	{
		if (this == &shape)
			return *this;
		delete[] name_;
		name_ = new char[strlen(shape.name_)];
		strcpy(name_, shape.name_);
		return *this;
	}

	Shape(const Shape& st) // конструктор копирования
	{
		name_ = new char[strlen(st.name_)];
		strcpy(name_, st.name_);
	}

	virtual ~Shape() { delete[] name_; }
};


class Circle : public Shape
{
private:
	double radius_;
	char* nameOfCircle_ = new char[20];

public:
	Circle(double radius_) : Shape()
	{
		setData(radius_);
	}

	void setData(double r)
	{
		radius_ = r;
		strcpy(nameOfCircle_, "Circle");
	}

	double Area()
	{
		return 3.14 * radius_ * radius_;
	}

	Circle& operator=(const Circle& tmp)  // оператор присваивания
	{
		if (this == &tmp)
			return *this;
		Shape::operator=(tmp);
		delete[] nameOfCircle_;
		nameOfCircle_ = new char[strlen(tmp.nameOfCircle_)];
		strcpy(nameOfCircle_, tmp.nameOfCircle_);
		radius_ = tmp.radius_;
		return *this;
	}

	Circle(const Circle& st) : Shape(st) // конструктор копирования
	{
		radius_ = st.radius_;
		nameOfCircle_ = new char[strlen(st.nameOfCircle_)];
		strcpy(nameOfCircle_, st.nameOfCircle_);
	}

	~Circle() { delete[] nameOfCircle_; }

};


class Square : public Shape
{
private:
	double side_;

public:
	Square(double side_) : Shape()
	{
		setData(side_);
	}

	void setData(double a)
	{
		side_ = a;
	}

	double Area()
	{
		return side_ * side_;
	}

	Square& operator=(const Square& tmp) // оператор присваивания
	{
		if (this == &tmp)
			return *this;
		Shape::operator=(tmp);
		side_ = tmp.side_;
		return *this;
	}

	Square(const Square& st) : Shape(st) // конструктор копирования
	{
		side_ = st.side_;
	}
};


class Triangle : public Shape
{
private:
	double a_, b_, c_;

public:
	Triangle(double a_, double b_, double c_) : Shape()
	{
		setData(a_, b_, c_);
	}

	void setData(double a, double b, double c)
	{
		a_ = a;
		b_ = b;
		c_ = c;
	}

	double Area()
	{
		double p = (a_ + b_ + c_) / 2;
		return sqrt(p * (p - a_) * (p - b_) * (p - c_));
	}

	Triangle& operator=(const Triangle& tmp) // оператор присваивания
	{
		if (this == &tmp)
			return *this;
		Shape::operator=(tmp);
		a_ = tmp.a_;
		b_ = tmp.b_;
		c_ = tmp.c_;
		return *this;
	}

	Triangle(const Triangle& st) : Shape(st) // кнструктор копирования
	{
		a_ = st.a_;
		b_ = st.b_;
		c_ = st.c_;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	Shape* array[3];
	Circle myCircle(3);
	Square mySquare(5);
	Triangle myTriangle(3, 4, 5);
	array[0] = &myCircle;
	array[1] = &mySquare;
	array[2] = &myTriangle;
	for (int i = 0; i < 3; i++)
	{
		cout << "Площадь фигуры " << i + 1 << " равна " << array[i]->Area() << endl;
	}
	Circle b = myCircle; // оператор присваивания
	Circle c(myCircle); // применяем конструктор копирования
	system("pause");
	return 0;
}