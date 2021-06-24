#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Invoker myinv;
	myinv.switchOn(); // включили
	myinv.switchOff(); // выкл
	myinv.switchOff(); // еще раз выкл, значит вкл
	for (int i = 0; i < 3; i++)
	{
		myinv.makebrighter(); // + €ркость
	}
	myinv.Undo(); // отмена €ркости
	myinv.Redo(); // возвращаем €ркость
	myinv.switchOff(); // выкл лампу
	myinv.Undo(); // обратно вкл
	system("pause");
	return 0;
}