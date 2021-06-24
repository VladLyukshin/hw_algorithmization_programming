#include <iostream>
#include <string>
using namespace std;


template <class myType>
class List // класс односвязаного списка
{
	struct Node // определяем структуру Node для класса односвязаного списка
	{
		Node* next_; // указатель на следующий элемент
		myType value_; // значение узла

		Node() // структура по умолчанию
		{
			next_ = NULL;
		}

		Node(const myType& a) // структура с параметром а
		{
			value_ = a;
			next_ = NULL;
		}
	};
private:
	Node* head_;// определяем указатель на голову односвязаного списка

public:
	List()// конструктор
	{
		head_ = NULL; // устанавливаем нуловый узел
	}
	List(myType a) // инициализация списка
	{
		head_ = NULL; // устанавливаем нуловый узел
		add(a); // добавляем переменную а
	}
	~List() // деструктор
	{
		while (head_) // пока голова не стана нул, очищаем список
		{
			clear_list(); // вызываем функцию удаления узла
		}
	}
	void clear_list() // удаление корня списка
	{
		if (head_) // если голова не пуста 
		{
			Node* new_head = head_->next_; // новую голову переносим на следующий элементв
			delete head_; // очищаем предыдущую
			head_ = new_head; // устанавливаем новую голову
		}
	}
	void remove_elem() // удаление узла из списка
	{
		Node* tmp = head_; // переменная tmp для обхода списка
		Node* free; // переменная для очистки удаляемого списка
		if (length() == 1) // если длина списка равна 1, то при удалении узла голова становится NULL
		{
			head_ = NULL;
			delete tmp; // очищаем значение удаляемого узла
		}
		else
		{
			while (tmp->next_->next_) // доходим до предпоследнего элемента
			{
				tmp = tmp->next_; // сдвигаем tmp 
			}
			free = tmp->next_; // запоминаем последний узел для удаления 
			tmp->next_ = NULL;// "отрезаем" последний узел
			delete free; // очищаем его данные
		}
	}
	bool is_empty() // проверка списка на пустоту
	{
		if (head_) // если голова пустая, то список пуст
		{
			return false;
		}
		return true;
	}
	void add(const myType& tmp) // добавление узла в начало списка
	{
		Node* new_node = new Node(tmp); // выделяем память под новый узел
		new_node->next_ = head_;
		head_ = new_node;
	}
	int length() // определение длины списка
	{
		int count = 0; // счетчик длины
		Node* tmp = head_;
		while (tmp->next_) // пока указатель next не NULL 
		{
			tmp = tmp->next_;
			count++;
		}
		count++;
		return count;
	}
	void swap() // взаимообмен 2х узлов списка
	{
		Node* pre_first = head_; // указатель на узел, находящийся перед 1м узлом, который нужно поменять
		Node* pre_second = head_; // указатель на узел, находящийся перед 2м узлом, который нужно поменять
		Node * first = head_; // указатель на 1й узел, который нужно поменять
		Node* second = head_; // указатель на 2й узел, который нужно поменять
		Node* next_first = head_; // указатель на узел, находящийся после 1го узла, который нужно поменять
		int first_num, second_num;
		cout << "Введите номера элементов, которые вы хотите обменять: ";
		cin >> first_num >> second_num;	
		if ((first_num <= 0) || (second_num <= 0) || (first_num > length()) || (second_num > length()) || (first_num == second_num))
		{
			cout << "Некорректный ввод!" << endl;
			return; // если вводятся некорректные данные, то прекращаем работу функции
		}
		if (abs(first_num - second_num) != 1) // случай, если узлы не соседние
		{
			if (first_num != 1) // случай, если 1й узел не головной
			{
				for (int i = 1; i < first_num - 1; i++) // проходим до необходимого узла
				{
					first = first->next_;
				}
				for (int i = 1; i < second_num - 1; i++) // проходим до необходимого узла
				{
					second = second->next_;
				}
				pre_first = first;// расставляем каждому узлу необходимые указатели
				next_first = first;
				pre_second = second;
				first = first->next_;
				next_first = next_first->next_->next_;
				second = second->next_;
				// ниже происходит взаимообмен 2х узлов
				first->next_ = second->next_; 
				second->next_ = next_first;
				pre_first->next_ = second;
				pre_second->next_ = first;
			}
			else // случай, если 1й узел, который нужно поменять является головным
			{
				for (int i = 1; i < second_num - 1; i++) // проходим до необходимого узла
				{
					second = second->next_;
				}
				pre_second = second;// расставляем каждому узлу необходимые указатели
				next_first = head_->next_;
				second = second->next_;
				// ниже происходит взаимообмен 2х узлов
				first->next_ = second->next_;
				second->next_ = next_first;
				pre_second->next_ = first;
				head_ = second;
			}
		}
		else // случай, если узлы соседние
		{
			if (first_num != 1) // случай, если 1й узел не головной
			{
				if (second_num != length()) // случай, если 2й узел не последний
				{
					for (int i = 1; i < first_num - 1; i++) // проходим до необходимого узла
					{
						first = first->next_;
					}
					pre_first = first;
					first = first->next_;
					for (int i = 1; i < second_num; i++) // проходим до необходимого узла
					{
						second = second->next_;
					}
					first->next_ = second->next_; // взаимообмен 2х узлов
					second->next_ = first;
					pre_first->next_ = second;
				}
				else // случай, если 2й узел последний
				{
					for (int i = 1; i < first_num - 1; i++) // проходим до необходимого узла
					{
						first = first->next_;
					}
					pre_first = first;
					first = first->next_;
					for (int i = 1; i < second_num; i++) // проходим до необходимого узла
					{
						second = second->next_;
					}
					pre_first->next_ = second; // взаимообмен 2х узлов
					second->next_ = first;
					first->next_ = NULL;
				}
			}
			else // случай, если 1й узел головной (то есть обмениваются 1й и 2й узлы)
			{
				first = head_->next_; // взаимообмен 2х узлов
				head_->next_ = head_->next_->next_;
				first->next_ = head_;
				head_ = first;
			}
		}
	}
	friend istream& operator>> (istream& is, List<myType>& tmp) // оператор ввода для класса односвязного списка
	{
		Node* new_node = new Node; // выделяем память под новый узел
		new_node->next_ = tmp.head_; // добавляем данный узел и вводим для него определенное значение
		tmp.head_ = new_node;
		is >> tmp.head_->value_; // вводим значение в новый узел
		return is;
	}
	friend ostream& operator<< (ostream& os, const List<myType>& tmp) // оператор вывода для класса односвязного списка
	{
		os << "Содержание односвязного списка:" << endl;
		Node* current = tmp.head_; // переменная для обхода списка
		while (current)
		{
			os << current->value_ << " "; // выводим значение узла
			current = current->next_; // переходим к следующему узлу
		}
		os << endl;
		return os;
	}

	List<myType>& operator=(const List<myType>& tmp) // оператор присваивания
	{
		if (this == &tmp)
			return *this;
		head_ = tmp.head_;
		return *this;
	}
};


class Pair // класс пары чисел
{
protected:
	int myInt; // переменная, хранящая значение int числа
	double myDouble; // переменная, хранящая значение double числа
public:
	Pair() { setData(0, 0); } // конструктор по умолчанию
	explicit Pair(int first, double second) { setData(first, second); } //  констурктор с параметрами
	void setData(int a, double b) // устанавливаем значения 
	{
		myInt = a;
		myDouble = b;
	}
	friend istream& operator>> (istream& is, Pair& tmp) // оператор ввода
	{
		is >> tmp.myInt >> tmp.myDouble;
		return is;
	}
	friend ostream& operator<< (ostream& os, const Pair& tmp) // оператор вывода
	{
		os << "Содержание класса Pair - " << tmp.myInt << ":" << tmp.myDouble << endl;
		return os;
	}
	Pair& operator=(const Pair& tmp) // оператор равенства
	{
		if (this == &tmp)
			return *this;
		myInt = tmp.myInt;
		myDouble = tmp.myDouble;
		return *this;
	}
};
