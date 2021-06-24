#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Password_Generator* generator = new Composit_Password_Generator(10); // â êîíñòðóêòîðå óêàçûâàåì ìèíèìàëüíóþ äëèíó ïàðîëÿ
	generator->add(new Digit_Generator(2)); // óñòàíàâëèâàåì, ÷òîáû â ïàðîëå áûëî 2 öèôðû
	generator->add(new Symbol_Generator(1)); // 2 ñèìâîëà
	generator->add(new Upper_Letter_Generator(5)); // 5 çàãëàâíûõ áóêâ
	generator->add(new Lower_Letter_Generator(3)); // 3 ïðîïèñíûõ áóêâû
	cout << "Ìèíèìàëüíàÿ äëèíà ïàðîëÿ: " << generator->length() << endl;
	cout << "Âñåâîçìîæíûå ñèìâîëû ïàðîëÿ: " << generator->allowed_chars() << endl;
	cout << "Ïàðîëü 1: " << generator->generate() << endl; 
	cout << "Ïàðîëü 2: " << generator->generate() << endl;
	cout << "Ïàðîëü 3: " << generator->generate() << endl;
	delete generator;
	return 0;
}
