#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Invoker myinv;
	myinv.switchOn(); // âêëþ÷èëè
	myinv.switchOff(); // âûêë
	myinv.switchOff(); // åùå ðàç âûêë, çíà÷èò âêë
	for (int i = 0; i < 3; i++)
	{
		myinv.makebrighter(); // + ÿðêîñòü
	}
	myinv.Undo(); // îòìåíà ÿðêîñòè
	myinv.Redo(); // âîçâðàùàåì ÿðêîñòü
	myinv.switchOff(); // âûêë ëàìïó
	myinv.Undo(); // îáðàòíî âêë
	system("pause");
	return 0;
}
