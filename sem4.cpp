#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;


class Product // создаем класс продуктов
{
private:

	string title_, country_; // строковые поля класса
	int volume_, total_; // целочисленные поля

public:

	Product(string title, string country, int volume, int total) // создаем констуктор с параметрами
	{
		setData(title, country, volume, total);
	}

	Product() // конструктор по умолчанию
	{
		setData("", "", 0, 0);
	}

	void setData(string title, string country, int volume, int total) // устанавливаем в поля класса переданные данные 
	{
		title_ = title;
		country_ = country;
		volume_ = volume;
		total_ = total;
	}

	friend bool operator> (const Product& first, const Product& second); // объявляем friend функции сравнения для дальнейших сортировок
	friend bool operator< (const Product& first, const Product& second);
	friend bool operator>= (const Product& first, const Product& second);
	friend bool operator<= (const Product& first, const Product& second);
	friend ostream& operator<< (ostream& os, const Product& tmp); // функция для вывода (не используется в программе, только при тесте, чтобы посмотреть как отсортировалось)
};


bool operator> (const Product& first, const Product& second) // переопределяем оператор > для класса Product
{
	if (first.title_ > second.title_) // сначала сравниваем по полю название
	{
		return true;
	}
	else
	{
		if (first.title_ < second.title_)
		{
			return false;
		}
		else 
		{
			if (first.volume_ > second.volume_) // если поля название равны, то сравниваем по объему
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}


bool operator< (const Product& first, const Product& second) 
{
	if (first.title_ < second.title_)
	{
		return true;
	}
	else
	{
		if (first.title_ > second.title_)
		{
			return false;
		}
		else
		{
			if (first.volume_ < second.volume_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}


bool operator>= (const Product& first, const Product& second)
{
	if (first.title_ >= second.title_)
	{
		return true;
	}
	else
	{
		if (first.title_ < second.title_)
		{
			return false;
		}
		else
		{
			if (first.volume_ >= second.volume_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}


bool operator<= (const Product& first, const Product& second)
{
	if (first.title_ <= second.title_)
	{
		return true;
	}
	else
	{
		if (first.title_ > second.title_)
		{
			return false;
		}
		else
		{
			if (first.volume_ <= second.volume_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}


ostream& operator<< (ostream& os, const Product& tmp) // переопределяем оператор вывода для класса Product 
{
	os << "Название товара - " << tmp.title_ << ", Страна товара - " << tmp.country_ << ", Объем продукции - " << tmp.volume_ << ", Сумма в рублях - " << tmp.total_ << endl;
	return os;
}


void filling_base(Product* list, string name, int count) // функция для считывания данных из файла и сохрание в массив классов
{
	ifstream inFile;
	inFile.open(name);
	if (!inFile.is_open()) // проверяем, что файл открылся успешно
	{
		cout << "Ошибка при открытии файла"; // если нет, то пишем об этом и выводим ошибку
		exit(EXIT_FAILURE);
	}
	string title, country; // временные переменные, куда мы считаем данные из файла, а потом из них сформируем элемент класса
	int volume, total;
	int counter = 0; // счетчик, чтобы загрузить заданное количество элементов из файла
	while (inFile.good() && counter < count) // пока файл читается и количество меньше заданного
	{
		inFile >> title >> country >> volume >> total; // читаем из файла поля для будущего класса 
		list[counter] = Product(title, country, volume, total); // создаем класс Product и записываем в переменную массива классов
		counter++; // увеличиваем счетчик
	}
	inFile.close(); // закрываем файл
}


unsigned int bubble_sort(Product* list, int count) // сортировка пузырьком
{
	unsigned int start_time = clock(); // начинаем засекать время
	Product tmp; // создаем временную переменную tmp класса Product, чтобы обмениваться значениями
	for (int i = 0; i < count - 1; i++) // реализуем сортировку пузырьком
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (list[j] > list[j + 1]) // сравниваем элементы
			{
				tmp = list[j]; // меняем переменные зачениями
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
	unsigned int end_time = clock(); // заканчиваем отсчет времени
	return end_time - start_time; // возвращаем сколько времени потратили на сортировку пузырьком
}


unsigned int shaker_sort(Product* list, int count) // шейкер-сортировка
{
	unsigned int start_time = clock(); // начинаем засекать время
	Product tmp;
	int beginning = 1, ending = count - 1; // установка начальной и конечной границ
	while (beginning <= ending) // пока начальный и конечный индексы не стали равны
	{
		for (int i = ending; i >= beginning; i--) // сначала двигаемся с конца в начало
		{
			if (list[i - 1] > list[i]) // сравниваем элементы 
			{
				tmp = list[i]; // обмениваемся значениями
				list[i] = list[i - 1];
				list[i - 1] = tmp;
			}
		}
		beginning++; // увеличиваем начальный индекс на 1, т к самый маленький элемент уже стоит на 1м месте

		for (int i = beginning + 1; i <= ending; i++) // теперь идем из начала в конец
		{
			if (list[i - 1] > list[i]) // сравниваем элементы
			{
				tmp = list[i]; // обмениваемся значениями
				list[i] = list[i - 1];
				list[i - 1] = tmp;
			}
		}
		ending--; // сдвигаем конечный индекс в конец, так как самый большой элемент уже стоит в конце
	}
	unsigned int end_time = clock(); // заканчиваем отсчет времени
	return end_time - start_time; // возвращаем сколько времени потратили на сортировку пузырьком
}


int main()
{
	setlocale(LC_ALL, "rus");
	Product* list = new Product[10000]; // выделяем динамически память для массива классов 
	string name = "database.txt"; // название файла
	int choice1, choice2;
	unsigned int result_time;
	cout << "Выберите размерность массива классов для сортировки:\n1 - для 100 элементов\n2 - для 200\n3 - для 500\n4 - для 1000\n5 - для 2000\n6 - для 5000\n7 - для 10000\n";
	cin >> choice1;
	switch (choice1) // производим выбор в зависимости от того, сколько элементов нужно отсортировать
	{
	case 1:
		filling_base(list, name, 100); // выгружаем 100 элементов из файла в массив классов
		cout << "Выберите сортировку:\n1 - сортировка пузырьком\n2 - шейкер-сортировка\n";
		cin >> choice2; // выбираем сортировку
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 100);
			cout << "Время работы сортировки пузырьком для 100 элементов равна " << result_time << " мс." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 100);
			cout << "Время работы шейкер-сортировки для 100 элементов равна " << result_time << " мс." << endl;
			break;
		default:
			cout << "Неправильный ввод! " << endl;
			break;
		}
		break;

	case 2:
		filling_base(list, name, 200); // аналогично 1му случаю
		cout << "Выберите сортировку:\n1 - сортировка пузырьком\n2 - шейкер-сортировка\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 200);
			cout << "Время работы сортировки пузырьком для 200 элементов равна " << result_time << " мс." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 200);
			cout << "Время работы шейкер-сортировки для 200 элементов равна " << result_time << " мс." << endl;
			break;
		default:
			cout << "Неправильный ввод!" << endl;
			break;
		}
		break;

	case 3:
		filling_base(list, name, 500);
		cout << "Выберите сортировку:\n1 - сортировка пузырьком\n2 - шейкер-сортировка\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 500);
			cout << "Время работы сортировки пузырьком для 500 элементов равна " << result_time << " мс." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 500);
			cout << "Время работы шейкер-сортировки для 500 элементов равна " << result_time << " мс." << endl;
			break;
		default:
			cout << "Неправильный ввод!" << endl;
			break;
		}
		break;

	case 4:
		filling_base(list, name, 1000);
		cout << "Выберите сортировку:\n1 - сортировка пузырьком\n2 - шейкер-сортировка\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 1000);
			cout << "Время работы сортировки пузырьком для 1000 элементов равна " << result_time << " мс." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 1000);
			cout << "Время работы шейкер-сортировки для 1000 элементов равна " << result_time << " мс." << endl;
			break;
		default:
			cout << "Неправильный ввод!" << endl;
			break;
		}
		break;

	case 5:
		filling_base(list, name, 2000);
		cout << "Выберите сортировку:\n1 - сортировка пузырьком\n2 - шейкер-сортировка\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 2000);
			cout << "Время работы сортировки пузырьком для 2000 элементов равна " << result_time << " мс." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 2000);
			cout << "Время работы шейкер-сортировки для 2000 элементов равна " << result_time << " мс." << endl;
			break;
		default:
			cout << "Неправильный ввод!" << endl;
			break;
		}
		break;

	case 6:
		filling_base(list, name, 5000);
		cout << "Выберите сортировку:\n1 - сортировка пузырьком\n2 - шейкер-сортировка\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 5000);
			cout << "Время работы сортировки пузырьком для 5000 элементов равна " << result_time << " мс." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 5000);
			cout << "Время работы шейкер-сортировки для 5000 элементов равна " << result_time << " мс." << endl;
			break;
		default:
			cout << "Неправильный ввод!" << endl;
			break;
		}
		break;

	case 7:
		filling_base(list, name, 10000);
		cout << "Выберите сортировку:\n1 - сортировка пузырьком\n2 - шейкер-сортировка\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 10000);
			cout << "Время работы сортировки пузырьком для 10000 элементов равна " << result_time << " мс." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 10000);
			cout << "Время работы шейкер-сортировки для 10000 элементов равна " << result_time << " мс." << endl;
			break;
		default:
			cout << "Неправильный ввод!" << endl;
			break;
		}
		break;

	default:
		cout << "Неправильный ввод!" << endl;
		break;
	}
	delete[] list; // очищаем память
	system("pause");
	return 0;
}