#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Password_Generator
{
public:
	virtual string generate() { return ""; }
	virtual const int length() = 0;
	virtual string allowed_chars() = 0;
	virtual void add(Password_Generator*) {}
	virtual ~Password_Generator() {}
};

class Digit_Generator : public Password_Generator
{
private:
	int count;
public:
	Digit_Generator(int tmp = 0)
	{
		count = tmp;
	}
	string allowed_chars()
	{
		return "0123456789";
	}
	const int length()
	{
		return count;
	}
};

class Symbol_Generator : public Password_Generator
{
private:
	int count;
public:
	Symbol_Generator(int tmp = 0)
	{
		count = tmp;
	}
	string allowed_chars()
	{
		return "!-?+#=";
	}
	const int length()
	{
		return count;
	}
};

class Upper_Letter_Generator : public Password_Generator
{
private:
	int count;
public:
	Upper_Letter_Generator(int tmp = 0)
	{
		count = tmp;
	}
	string allowed_chars()
	{
		string tmp = "";
		for (char letter = 'A'; letter <= 'Z'; letter++)
		{
			tmp += letter;
		}
		return tmp;
	}
	const int length()
	{
		return count;
	}
};

class Lower_Letter_Generator : public Password_Generator
{
private:
	int count;
public:
	Lower_Letter_Generator(int tmp = 0)
	{
		count = tmp;
	}
	string allowed_chars()
	{
		string tmp = "";
		for (char letter = 'a'; letter <= 'z'; letter++)
		{
			tmp += letter;
		}
		return tmp;
	}
	const int length()
	{
		return count;
	}
};

class Composit_Password_Generator : public Password_Generator
{
private:
	vector <Password_Generator*> list_of_criteria;
	int min_length_of_string;

public:
	Composit_Password_Generator(int count)
	{
		min_length_of_string = count;
	}

	string generate()
	{
		string result = "";
		string tmp;
		int counter = 0;
		int count_of_symbols = 0;  
		for (int i = 0; i < list_of_criteria.size(); i++)
		{
			count_of_symbols += list_of_criteria[i]->length();
		}
		if (count_of_symbols < min_length_of_string)
		{
			cout << "Íåêîððåêòíûå ïàðàìåòðû: äëèíà çàïðàøèâàåìîãî ïàðîëÿ ìåíüøå ìèíèìàëüíîé äëèíû!" << endl;
			return "ERROR!";
		}
		else
		{
			vector <int> ar(count_of_symbols); // èñïîëüçóåì âåêòîð, ÷òîáû íà ðàíäîìíûå ìåñòà â ñòðîêå ïîñòàâèòü ðàíäîìíûé ñèìâîë òðåáóåìîãî òèïà
			for (int i = 0; i < count_of_symbols; i++)
			{
				ar[i] = i;
			}
			random_shuffle(ar.begin(), ar.end());
			for (int i = 0; i < count_of_symbols; i++)
			{
				result += "."; // çàïîëíèì äëÿ íà÷àëà ïàðîëü ñòðîêîé çàäàííîé äëèíû çàïîëíåííîé òî÷êàìè, êîòîðûå áóäåì çàìåíÿòü íà òðåáóåìîå êîëè÷åñòâî çàäàííûõ òèïîâ
			}
			for (int i = 0; i < list_of_criteria.size(); i++)
			{
				int tm = counter;
				for (int j = 0; j < list_of_criteria[i]->length(); j++)
				{
					result[ar[tm]] = list_of_criteria[i]->allowed_chars()[rand() % list_of_criteria[i]->allowed_chars().length()];
					tm++;
				}
				counter += list_of_criteria[i]->length();
			}
			ar.clear();
			return result;
		}
	}

	void add(Password_Generator* tmp)
	{
		list_of_criteria.push_back(tmp);
	}

	const int length()
	{
		return min_length_of_string;
	}

	string allowed_chars()
	{
		string tmp = "";
		for (int i = 0; i < list_of_criteria.size(); i++)
		{
			tmp += list_of_criteria[i]->allowed_chars();
		}
		return tmp;
	}

	~Composit_Password_Generator()
	{
		for (int i = 0; i < list_of_criteria.size(); i++)
		{
			delete list_of_criteria[i];
		}
		list_of_criteria.clear();
	}
};
