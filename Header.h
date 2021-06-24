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
		if (power >= 1) // если просим вкл, а лампа и так вкл, то выкл
		{
			power = 0;
			cout << "Просим включить, а лампа вкл, значит лампа выкл" << endl;
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
			cout << "Яркость равна " << power << endl;
		}
	}
	void MakeLessBrighter()
	{
		if (power > 1)
		{
			power -= 1;
			cout << "Яркость равна " << power << endl;
		}
	}
	void TurnOff()
	{
		if (power != 0) 
		{
			power = 0;
		}
		else // если лампа и так выкл, и мы еще раз выкл, то вкл
		{
			power = 1;
			cout << "Просим выклюить, а лампа выкл, значит лампа вкл" << endl;
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
		cout << "Лампа включена" << endl;
	}
	void unExecute()
	{
		lamp->TurnOff();
		cout << "Лампа выключена" << endl;
	}
};


class MakeBrighter : public Command
{
public:
	void Execute()
	{
		lamp->MakeBrighter();
		cout << "Увеличили яркость лампы" << endl;
	}
	void unExecute()
	{
		lamp->MakeLessBrighter();
		cout << "Снизили яркость лампы" << endl;
	}
};


class TurnOff : public Command
{
public:
	void Execute()
	{
		lamp->TurnOff();
		cout << "Лампа выключена" << endl;
	}
	void unExecute()
	{
		lamp->TurnOn();
		cout << "Лампа включена" << endl;
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
			cout << "Ошибка! Нечего отменять" << endl;
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

