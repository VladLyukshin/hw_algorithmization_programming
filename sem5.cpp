#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void show_data(const vector <string>& numbers, const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << numbers[i] << endl;
	}
}


void input_numbers(vector <string>& numbers, const int count)
{
	string tmp;
	cin.ignore();
	for (int i = 0; i < count; i++)
	{
		cout << "Введите номер телефона: ";
		getline(cin, tmp);
		numbers.push_back(tmp);
	}
}


void change_numbers(vector <string>& numbers, const int count)
{
	int position;
	for (int i = 0; i < count; i++)
	{
		position = numbers[i].find(" ");
		while (position != -1)
		{
			numbers[i].erase(position, 1);
			position = numbers[i].find(" ");
		}
		if (numbers[i].length() == 10)
		{
			numbers[i].insert(0, "+7");
		}
		if (numbers[i].length() == 11)
		{
			numbers[i].insert(0, "+");
		}
		if (numbers[i][1] == '8')
		{
			numbers[i][1] = '7';
		}
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	vector <string> numbers;
	int count;
	cout << "Введите количество номеров, которые вы хотите ввести: ";
	cin >> count;
    input_numbers(numbers, count);
	change_numbers(numbers, count);
	sort(numbers.begin(), numbers.end());
	cout << "Вывод измененных номеров телефонов: " << endl;
	show_data(numbers, count);
	system("pause");
	return 0;
}