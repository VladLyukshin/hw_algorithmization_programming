#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Password_Generator* generator = new Composit_Password_Generator(10); // в конструкторе указываем минимальную длину пароля
	generator->add(new Digit_Generator(2)); // устанавливаем, чтобы в пароле было 2 цифры
	generator->add(new Symbol_Generator(1)); // 2 символа
	generator->add(new Upper_Letter_Generator(5)); // 5 заглавных букв
	generator->add(new Lower_Letter_Generator(3)); // 3 прописных буквы
	cout << "Минимальная длина пароля: " << generator->length() << endl;
	cout << "Всевозможные символы пароля: " << generator->allowed_chars() << endl;
	cout << "Пароль 1: " << generator->generate() << endl; 
	cout << "Пароль 2: " << generator->generate() << endl;
	cout << "Пароль 3: " << generator->generate() << endl;
	delete generator;
	return 0;
}