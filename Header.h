#include <iostream>
#include <string>
using namespace std;


template <class myType>
class List // ����� ������������� ������
{
	struct Node // ���������� ��������� Node ��� ������ ������������� ������
	{
		Node* next_; // ��������� �� ��������� �������
		myType value_; // �������� ����

		Node() // ��������� �� ���������
		{
			next_ = NULL;
		}

		Node(const myType& a) // ��������� � ���������� �
		{
			value_ = a;
			next_ = NULL;
		}
	};
private:
	Node* head_;// ���������� ��������� �� ������ ������������� ������

public:
	List()// �����������
	{
		head_ = NULL; // ������������� ������� ����
	}
	List(myType a) // ������������� ������
	{
		head_ = NULL; // ������������� ������� ����
		add(a); // ��������� ���������� �
	}
	~List() // ����������
	{
		while (head_) // ���� ������ �� ����� ���, ������� ������
		{
			clear_list(); // �������� ������� �������� ����
		}
	}
	void clear_list() // �������� ����� ������
	{
		if (head_) // ���� ������ �� ����� 
		{
			Node* new_head = head_->next_; // ����� ������ ��������� �� ��������� ��������
			delete head_; // ������� ����������
			head_ = new_head; // ������������� ����� ������
		}
	}
	void remove_elem() // �������� ���� �� ������
	{
		Node* tmp = head_; // ���������� tmp ��� ������ ������
		Node* free; // ���������� ��� ������� ���������� ������
		if (length() == 1) // ���� ����� ������ ����� 1, �� ��� �������� ���� ������ ���������� NULL
		{
			head_ = NULL;
			delete tmp; // ������� �������� ���������� ����
		}
		else
		{
			while (tmp->next_->next_) // ������� �� �������������� ��������
			{
				tmp = tmp->next_; // �������� tmp 
			}
			free = tmp->next_; // ���������� ��������� ���� ��� �������� 
			tmp->next_ = NULL;// "��������" ��������� ����
			delete free; // ������� ��� ������
		}
	}
	bool is_empty() // �������� ������ �� �������
	{
		if (head_) // ���� ������ ������, �� ������ ����
		{
			return false;
		}
		return true;
	}
	void add(const myType& tmp) // ���������� ���� � ������ ������
	{
		Node* new_node = new Node(tmp); // �������� ������ ��� ����� ����
		new_node->next_ = head_;
		head_ = new_node;
	}
	int length() // ����������� ����� ������
	{
		int count = 0; // ������� �����
		Node* tmp = head_;
		while (tmp->next_) // ���� ��������� next �� NULL 
		{
			tmp = tmp->next_;
			count++;
		}
		count++;
		return count;
	}
	void swap() // ����������� 2� ����� ������
	{
		Node* pre_first = head_; // ��������� �� ����, ����������� ����� 1� �����, ������� ����� ��������
		Node* pre_second = head_; // ��������� �� ����, ����������� ����� 2� �����, ������� ����� ��������
		Node * first = head_; // ��������� �� 1� ����, ������� ����� ��������
		Node* second = head_; // ��������� �� 2� ����, ������� ����� ��������
		Node* next_first = head_; // ��������� �� ����, ����������� ����� 1�� ����, ������� ����� ��������
		int first_num, second_num;
		cout << "������� ������ ���������, ������� �� ������ ��������: ";
		cin >> first_num >> second_num;	
		if ((first_num <= 0) || (second_num <= 0) || (first_num > length()) || (second_num > length()) || (first_num == second_num))
		{
			cout << "������������ ����!" << endl;
			return; // ���� �������� ������������ ������, �� ���������� ������ �������
		}
		if (abs(first_num - second_num) != 1) // ������, ���� ���� �� ��������
		{
			if (first_num != 1) // ������, ���� 1� ���� �� ��������
			{
				for (int i = 1; i < first_num - 1; i++) // �������� �� ������������ ����
				{
					first = first->next_;
				}
				for (int i = 1; i < second_num - 1; i++) // �������� �� ������������ ����
				{
					second = second->next_;
				}
				pre_first = first;// ����������� ������� ���� ����������� ���������
				next_first = first;
				pre_second = second;
				first = first->next_;
				next_first = next_first->next_->next_;
				second = second->next_;
				// ���� ���������� ����������� 2� �����
				first->next_ = second->next_; 
				second->next_ = next_first;
				pre_first->next_ = second;
				pre_second->next_ = first;
			}
			else // ������, ���� 1� ����, ������� ����� �������� �������� ��������
			{
				for (int i = 1; i < second_num - 1; i++) // �������� �� ������������ ����
				{
					second = second->next_;
				}
				pre_second = second;// ����������� ������� ���� ����������� ���������
				next_first = head_->next_;
				second = second->next_;
				// ���� ���������� ����������� 2� �����
				first->next_ = second->next_;
				second->next_ = next_first;
				pre_second->next_ = first;
				head_ = second;
			}
		}
		else // ������, ���� ���� ��������
		{
			if (first_num != 1) // ������, ���� 1� ���� �� ��������
			{
				if (second_num != length()) // ������, ���� 2� ���� �� ���������
				{
					for (int i = 1; i < first_num - 1; i++) // �������� �� ������������ ����
					{
						first = first->next_;
					}
					pre_first = first;
					first = first->next_;
					for (int i = 1; i < second_num; i++) // �������� �� ������������ ����
					{
						second = second->next_;
					}
					first->next_ = second->next_; // ����������� 2� �����
					second->next_ = first;
					pre_first->next_ = second;
				}
				else // ������, ���� 2� ���� ���������
				{
					for (int i = 1; i < first_num - 1; i++) // �������� �� ������������ ����
					{
						first = first->next_;
					}
					pre_first = first;
					first = first->next_;
					for (int i = 1; i < second_num; i++) // �������� �� ������������ ����
					{
						second = second->next_;
					}
					pre_first->next_ = second; // ����������� 2� �����
					second->next_ = first;
					first->next_ = NULL;
				}
			}
			else // ������, ���� 1� ���� �������� (�� ���� ������������ 1� � 2� ����)
			{
				first = head_->next_; // ����������� 2� �����
				head_->next_ = head_->next_->next_;
				first->next_ = head_;
				head_ = first;
			}
		}
	}
	friend istream& operator>> (istream& is, List<myType>& tmp) // �������� ����� ��� ������ ������������ ������
	{
		Node* new_node = new Node; // �������� ������ ��� ����� ����
		new_node->next_ = tmp.head_; // ��������� ������ ���� � ������ ��� ���� ������������ ��������
		tmp.head_ = new_node;
		is >> tmp.head_->value_; // ������ �������� � ����� ����
		return is;
	}
	friend ostream& operator<< (ostream& os, const List<myType>& tmp) // �������� ������ ��� ������ ������������ ������
	{
		os << "���������� ������������ ������:" << endl;
		Node* current = tmp.head_; // ���������� ��� ������ ������
		while (current)
		{
			os << current->value_ << " "; // ������� �������� ����
			current = current->next_; // ��������� � ���������� ����
		}
		os << endl;
		return os;
	}

	List<myType>& operator=(const List<myType>& tmp) // �������� ������������
	{
		if (this == &tmp)
			return *this;
		head_ = tmp.head_;
		return *this;
	}
};


class Pair // ����� ���� �����
{
protected:
	int myInt; // ����������, �������� �������� int �����
	double myDouble; // ����������, �������� �������� double �����
public:
	Pair() { setData(0, 0); } // ����������� �� ���������
	explicit Pair(int first, double second) { setData(first, second); } //  ����������� � �����������
	void setData(int a, double b) // ������������� �������� 
	{
		myInt = a;
		myDouble = b;
	}
	friend istream& operator>> (istream& is, Pair& tmp) // �������� �����
	{
		is >> tmp.myInt >> tmp.myDouble;
		return is;
	}
	friend ostream& operator<< (ostream& os, const Pair& tmp) // �������� ������
	{
		os << "���������� ������ Pair - " << tmp.myInt << ":" << tmp.myDouble << endl;
		return os;
	}
	Pair& operator=(const Pair& tmp) // �������� ���������
	{
		if (this == &tmp)
			return *this;
		myInt = tmp.myInt;
		myDouble = tmp.myDouble;
		return *this;
	}
};