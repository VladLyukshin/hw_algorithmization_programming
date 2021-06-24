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
		//Area();  если вызывать чистую виртуальную функцию в конструкторе, то происходит ошибка (Debug error)
	}

	virtual double Area() = 0; // чистая виртуальная функция

	virtual Shape& operator=(const Shape& shape) // оператор присваивания
	{
		if (this == &shape)
			return *this;
		strcpy(name_, shape.name_);
		return *this;
	}

	Shape(const Shape& st) // конструктор копирования
	{
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

	Circle& operator=(const Circle& tmp)
	{
		if (this == &tmp)
			return *this;
		Shape::operator=(tmp);
		radius_ = tmp.radius_;
		strcpy(name_, tmp.name_);
		return *this;
	}

	Circle(const Circle& st)
	{
		radius_ = st.radius_;
		strcpy(name_, st.name_);
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

	Square& operator=(const Square& tmp)
	{
		if (this == &tmp)
			return *this;
		Shape::operator=(tmp);
		side_ = tmp.side_;
		return *this;
	}

	Square(const Square& st)
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

	Triangle& operator=(const Triangle& tmp)
	{
		if (this == &tmp)
			return *this;
		Shape::operator=(tmp);
		a_ = tmp.a_;
		b_ = tmp.b_;
		c_ = tmp.c_;
		return *this;
	}

	Triangle(const Triangle& st)
	{
		a_ = st.a_;
		b_ = st.b_;
		c_ = st.c_;
	}
};


double Shape::Area()
{
	cout << "\nПроверка работы чистой виртуальной функции\n"; // даем определение чистой виртуальной функции 
	return Area(); 
}

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
	//Shape a; пробуем создать элемент класса  Shape, но выходит ошибка, т к Shape является абстрактным классом и объект такого класса создать невозможно
	system("pause");
	return 0;
}