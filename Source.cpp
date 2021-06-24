#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
bool flag_read = true;


vector <int> read_file(string title) // функция для считывания файла
{
	int tmp;
	vector <int> arr;
	ifstream fin(title);
	while (fin.good())
	{
		fin >> tmp;
		arr.push_back(tmp);
	}
	fin.close();
	return arr; // возвращаем вектор чисел из файла
}


void thr_func(string name, vector <int>& final_array, const int i, vector <int>& my_arr) // функция для потоков, чтобы они парарелльно считывали каждый свой файл
{
	my_arr = read_file(name);
	if (my_arr.empty())
	{
		flag_read = false; // флаг на проверку считался ли файл
	}
}

int my_function(int n, string* filenames)
{
	vector <int> final_array;
	thread* thread_array = new thread[n];
	bool flag = false; // флаг для подсчета последовательностей чисел
	int result = 0;
	vector <int>* tmp = new vector <int>[n];
	for (int i = 0; i < n; i++)
	{
		thread_array[i] = thread(thr_func, filenames[i], ref(final_array), i, ref(tmp[i]));
		if (!flag_read)
		{
			return -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		thread_array[i].join();
	}
	for (int i = 0; i < n; i++)
	{
		final_array.insert(final_array.end(), tmp[i].begin(), tmp[i].end());
		if (tmp[i].size() == 0)
		{
			return -1;
		}
		tmp[i].clear();
	}
	for (int i = 0; i < final_array.size(); i++)
	{
		cout << final_array[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < final_array.size() - 1; i++)
	{
		if (final_array[i] == final_array[i + 1])
		{
			if (!flag)
			{
				result++;
				flag = true;
			}
		}
		else
		{
			flag = false;
		}
	}
	final_array.clear();
	delete [] tmp;
	delete [] thread_array;
	return result;
}


int main()
{
	int n;
	string* filenames;
	cout << "Input n: ";
	cin >> n;
	filenames = new string[n];
	cout << "Input titles of files" << endl;
	for (int i = 0; i < n; i++)
	{
		string title;
		cout << "File " << i + 1 << ": " << endl;
		cin >> title;
		filenames[i] = title;
	}
	cout << "Number of sites of constancy is " << my_function(n, filenames) << endl;
	delete[] filenames;
	return 0;
}