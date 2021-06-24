#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;


class Product // ������� ����� ���������
{
private:

	string title_, country_; // ��������� ���� ������
	int volume_, total_; // ������������� ����

public:

	Product(string title, string country, int volume, int total) // ������� ���������� � �����������
	{
		setData(title, country, volume, total);
	}

	Product() // ����������� �� ���������
	{
		setData("", "", 0, 0);
	}

	void setData(string title, string country, int volume, int total) // ������������� � ���� ������ ���������� ������ 
	{
		title_ = title;
		country_ = country;
		volume_ = volume;
		total_ = total;
	}

	friend bool operator> (const Product& first, const Product& second); // ��������� friend ������� ��������� ��� ���������� ����������
	friend bool operator< (const Product& first, const Product& second);
	friend bool operator>= (const Product& first, const Product& second);
	friend bool operator<= (const Product& first, const Product& second);
	friend ostream& operator<< (ostream& os, const Product& tmp); // ������� ��� ������ (�� ������������ � ���������, ������ ��� �����, ����� ���������� ��� ���������������)
};


bool operator> (const Product& first, const Product& second) // �������������� �������� > ��� ������ Product
{
	if (first.title_ > second.title_) // ������� ���������� �� ���� ��������
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
			if (first.volume_ > second.volume_) // ���� ���� �������� �����, �� ���������� �� ������
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


ostream& operator<< (ostream& os, const Product& tmp) // �������������� �������� ������ ��� ������ Product 
{
	os << "�������� ������ - " << tmp.title_ << ", ������ ������ - " << tmp.country_ << ", ����� ��������� - " << tmp.volume_ << ", ����� � ������ - " << tmp.total_ << endl;
	return os;
}


void filling_base(Product* list, string name, int count) // ������� ��� ���������� ������ �� ����� � �������� � ������ �������
{
	ifstream inFile;
	inFile.open(name);
	if (!inFile.is_open()) // ���������, ��� ���� �������� �������
	{
		cout << "������ ��� �������� �����"; // ���� ���, �� ����� �� ���� � ������� ������
		exit(EXIT_FAILURE);
	}
	string title, country; // ��������� ����������, ���� �� ������� ������ �� �����, � ����� �� ��� ���������� ������� ������
	int volume, total;
	int counter = 0; // �������, ����� ��������� �������� ���������� ��������� �� �����
	while (inFile.good() && counter < count) // ���� ���� �������� � ���������� ������ ���������
	{
		inFile >> title >> country >> volume >> total; // ������ �� ����� ���� ��� �������� ������ 
		list[counter] = Product(title, country, volume, total); // ������� ����� Product � ���������� � ���������� ������� �������
		counter++; // ����������� �������
	}
	inFile.close(); // ��������� ����
}


unsigned int bubble_sort(Product* list, int count) // ���������� ���������
{
	unsigned int start_time = clock(); // �������� �������� �����
	Product tmp; // ������� ��������� ���������� tmp ������ Product, ����� ������������ ����������
	for (int i = 0; i < count - 1; i++) // ��������� ���������� ���������
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (list[j] > list[j + 1]) // ���������� ��������
			{
				tmp = list[j]; // ������ ���������� ���������
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
	unsigned int end_time = clock(); // ����������� ������ �������
	return end_time - start_time; // ���������� ������� ������� ��������� �� ���������� ���������
}


unsigned int shaker_sort(Product* list, int count) // ������-����������
{
	unsigned int start_time = clock(); // �������� �������� �����
	Product tmp;
	int beginning = 1, ending = count - 1; // ��������� ��������� � �������� ������
	while (beginning <= ending) // ���� ��������� � �������� ������� �� ����� �����
	{
		for (int i = ending; i >= beginning; i--) // ������� ��������� � ����� � ������
		{
			if (list[i - 1] > list[i]) // ���������� �������� 
			{
				tmp = list[i]; // ������������ ����������
				list[i] = list[i - 1];
				list[i - 1] = tmp;
			}
		}
		beginning++; // ����������� ��������� ������ �� 1, � � ����� ��������� ������� ��� ����� �� 1� �����

		for (int i = beginning + 1; i <= ending; i++) // ������ ���� �� ������ � �����
		{
			if (list[i - 1] > list[i]) // ���������� ��������
			{
				tmp = list[i]; // ������������ ����������
				list[i] = list[i - 1];
				list[i - 1] = tmp;
			}
		}
		ending--; // �������� �������� ������ � �����, ��� ��� ����� ������� ������� ��� ����� � �����
	}
	unsigned int end_time = clock(); // ����������� ������ �������
	return end_time - start_time; // ���������� ������� ������� ��������� �� ���������� ���������
}


int main()
{
	setlocale(LC_ALL, "rus");
	Product* list = new Product[10000]; // �������� ����������� ������ ��� ������� ������� 
	string name = "database.txt"; // �������� �����
	int choice1, choice2;
	unsigned int result_time;
	cout << "�������� ����������� ������� ������� ��� ����������:\n1 - ��� 100 ���������\n2 - ��� 200\n3 - ��� 500\n4 - ��� 1000\n5 - ��� 2000\n6 - ��� 5000\n7 - ��� 10000\n";
	cin >> choice1;
	switch (choice1) // ���������� ����� � ����������� �� ����, ������� ��������� ����� �������������
	{
	case 1:
		filling_base(list, name, 100); // ��������� 100 ��������� �� ����� � ������ �������
		cout << "�������� ����������:\n1 - ���������� ���������\n2 - ������-����������\n";
		cin >> choice2; // �������� ����������
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 100);
			cout << "����� ������ ���������� ��������� ��� 100 ��������� ����� " << result_time << " ��." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 100);
			cout << "����� ������ ������-���������� ��� 100 ��������� ����� " << result_time << " ��." << endl;
			break;
		default:
			cout << "������������ ����! " << endl;
			break;
		}
		break;

	case 2:
		filling_base(list, name, 200); // ���������� 1�� ������
		cout << "�������� ����������:\n1 - ���������� ���������\n2 - ������-����������\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 200);
			cout << "����� ������ ���������� ��������� ��� 200 ��������� ����� " << result_time << " ��." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 200);
			cout << "����� ������ ������-���������� ��� 200 ��������� ����� " << result_time << " ��." << endl;
			break;
		default:
			cout << "������������ ����!" << endl;
			break;
		}
		break;

	case 3:
		filling_base(list, name, 500);
		cout << "�������� ����������:\n1 - ���������� ���������\n2 - ������-����������\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 500);
			cout << "����� ������ ���������� ��������� ��� 500 ��������� ����� " << result_time << " ��." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 500);
			cout << "����� ������ ������-���������� ��� 500 ��������� ����� " << result_time << " ��." << endl;
			break;
		default:
			cout << "������������ ����!" << endl;
			break;
		}
		break;

	case 4:
		filling_base(list, name, 1000);
		cout << "�������� ����������:\n1 - ���������� ���������\n2 - ������-����������\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 1000);
			cout << "����� ������ ���������� ��������� ��� 1000 ��������� ����� " << result_time << " ��." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 1000);
			cout << "����� ������ ������-���������� ��� 1000 ��������� ����� " << result_time << " ��." << endl;
			break;
		default:
			cout << "������������ ����!" << endl;
			break;
		}
		break;

	case 5:
		filling_base(list, name, 2000);
		cout << "�������� ����������:\n1 - ���������� ���������\n2 - ������-����������\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 2000);
			cout << "����� ������ ���������� ��������� ��� 2000 ��������� ����� " << result_time << " ��." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 2000);
			cout << "����� ������ ������-���������� ��� 2000 ��������� ����� " << result_time << " ��." << endl;
			break;
		default:
			cout << "������������ ����!" << endl;
			break;
		}
		break;

	case 6:
		filling_base(list, name, 5000);
		cout << "�������� ����������:\n1 - ���������� ���������\n2 - ������-����������\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 5000);
			cout << "����� ������ ���������� ��������� ��� 5000 ��������� ����� " << result_time << " ��." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 5000);
			cout << "����� ������ ������-���������� ��� 5000 ��������� ����� " << result_time << " ��." << endl;
			break;
		default:
			cout << "������������ ����!" << endl;
			break;
		}
		break;

	case 7:
		filling_base(list, name, 10000);
		cout << "�������� ����������:\n1 - ���������� ���������\n2 - ������-����������\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			result_time = bubble_sort(list, 10000);
			cout << "����� ������ ���������� ��������� ��� 10000 ��������� ����� " << result_time << " ��." << endl;
			break;
		case 2:
			result_time = shaker_sort(list, 10000);
			cout << "����� ������ ������-���������� ��� 10000 ��������� ����� " << result_time << " ��." << endl;
			break;
		default:
			cout << "������������ ����!" << endl;
			break;
		}
		break;

	default:
		cout << "������������ ����!" << endl;
		break;
	}
	delete[] list; // ������� ������
	system("pause");
	return 0;
}