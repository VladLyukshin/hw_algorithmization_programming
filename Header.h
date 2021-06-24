#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Lamp
{
private:
	int power;
public:
	void TurnOn()
	{
		if (power >= 1) // ���� ������ ���, � ����� � ��� ���, �� ����
		{
			power = 0;
			cout << "������ ��������, � ����� ���, ������ ����� ����" << endl;
		}
		else
		{
			power = 1;
		}
	}
	void MakeBrighter()
	{
		if (power < 5)
		{
			power += 1;
			cout << "������� ����� " << power << endl;
		}
	}
	void MakeLessBrighter()
	{
		if (power > 1)
		{
			power -= 1;
			cout << "������� ����� " << power << endl;
		}
	}
	void TurnOff()
	{
		if (power != 0) 
		{
			power = 0;
		}
		else // ���� ����� � ��� ����, � �� ��� ��� ����, �� ���
		{
			power = 1;
			cout << "������ ��������, � ����� ����, ������ ����� ���" << endl;
		}
	} 
};


class Command
{
protected:
	Lamp* lamp;
public:
	virtual ~Command() { delete lamp; }
	virtual void Execute() = 0;
	virtual void unExecute() = 0;

	void setLamp(Lamp*  tmp)
	{
		lamp = tmp;
	} 
};



class TurnOn : public Command
{
public:
	void Execute()
	{
		lamp->TurnOn();
		cout << "����� ��������" << endl;
	}
	void unExecute()
	{
		lamp->TurnOff();
		cout << "����� ���������" << endl;
	}
};


class MakeBrighter : public Command
{
public:
	void Execute()
	{
		lamp->MakeBrighter();
		cout << "��������� ������� �����" << endl;
	}
	void unExecute()
	{
		lamp->MakeLessBrighter();
		cout << "������� ������� �����" << endl;
	}
};


class TurnOff : public Command
{
public:
	void Execute()
	{
		lamp->TurnOff();
		cout << "����� ���������" << endl;
	}
	void unExecute()
	{
		lamp->TurnOn();
		cout << "����� ��������" << endl;
	}
};


class Invoker
{
private:
	vector <Command*> DoneCommands;
	Lamp lamp;
	Command* command;

public:
	void switchOn()
	{
		command = new TurnOn();
		command->setLamp(&lamp);
		command->Execute();
		DoneCommands.push_back(command);
	}
	void switchOff()
	{
		command = new TurnOff();
		command->setLamp(&lamp);
		command->Execute();
		DoneCommands.push_back(command);
	}
	void makebrighter()
	{
		command = new MakeBrighter();
		command->setLamp(&lamp);
		command->Execute();
		DoneCommands.push_back(command);
	}
	void Undo() 
	{
		if (DoneCommands.size() == 0)
		{
			cout << "������! ������ ��������" << endl;
		}
		else
		{
			DoneCommands[DoneCommands.size() - 1]->unExecute();
			command = DoneCommands.back();
			DoneCommands.pop_back();
		}
	}
	void Redo() 
	{
		DoneCommands[DoneCommands.size() - 1]->Execute();
		DoneCommands.push_back(DoneCommands[DoneCommands.size() - 1]);
	}
	~Invoker()
	{
		delete command;
		for (int i = 0; i < DoneCommands.size(); i++)
		{
			delete DoneCommands[i];
		}
		DoneCommands.clear();
	}
};

