#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Invoker myinv;
	myinv.switchOn(); // ��������
	myinv.switchOff(); // ����
	myinv.switchOff(); // ��� ��� ����, ������ ���
	for (int i = 0; i < 3; i++)
	{
		myinv.makebrighter(); // + �������
	}
	myinv.Undo(); // ������ �������
	myinv.Redo(); // ���������� �������
	myinv.switchOff(); // ���� �����
	myinv.Undo(); // ������� ���
	system("pause");
	return 0;
}