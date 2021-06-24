#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Password_Generator* generator = new Composit_Password_Generator(10); // � ������������ ��������� ����������� ����� ������
	generator->add(new Digit_Generator(2)); // �������������, ����� � ������ ���� 2 �����
	generator->add(new Symbol_Generator(1)); // 2 �������
	generator->add(new Upper_Letter_Generator(5)); // 5 ��������� ����
	generator->add(new Lower_Letter_Generator(3)); // 3 ��������� �����
	cout << "����������� ����� ������: " << generator->length() << endl;
	cout << "������������ ������� ������: " << generator->allowed_chars() << endl;
	cout << "������ 1: " << generator->generate() << endl; 
	cout << "������ 2: " << generator->generate() << endl;
	cout << "������ 3: " << generator->generate() << endl;
	delete generator;
	return 0;
}