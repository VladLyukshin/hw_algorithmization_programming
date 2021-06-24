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
		if (power >= 1) // åñëè ïðîñèì âêë, à ëàìïà è òàê âêë, òî âûêë
		{
			power = 0;
			cout << "Ïðîñèì âêëþ÷èòü, à ëàìïà âêë, çíà÷èò ëàìïà âûêë" << endl;
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
			cout << "ßðêîñòü ðàâíà " << power << endl;
		}
	}
	void MakeLessBrighter()
	{
		if (power > 1)
		{
			power -= 1;
			cout << "ßðêîñòü ðàâíà " << power << endl;
		}
	}
	void TurnOff()
	{
		if (power != 0) 
		{
			power = 0;
		}
		else // åñëè ëàìïà è òàê âûêë, è ìû åùå ðàç âûêë, òî âêë
		{
			power = 1;
			cout << "Ïðîñèì âûêëþèòü, à ëàìïà âûêë, çíà÷èò ëàìïà âêë" << endl;
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
		cout << "Ëàìïà âêëþ÷åíà" << endl;
	}
	void unExecute()
	{
		lamp->TurnOff();
		cout << "Ëàìïà âûêëþ÷åíà" << endl;
	}
};


class MakeBrighter : public Command
{
public:
	void Execute()
	{
		lamp->MakeBrighter();
		cout << "Óâåëè÷èëè ÿðêîñòü ëàìïû" << endl;
	}
	void unExecute()
	{
		lamp->MakeLessBrighter();
		cout << "Ñíèçèëè ÿðêîñòü ëàìïû" << endl;
	}
};


class TurnOff : public Command
{
public:
	void Execute()
	{
		lamp->TurnOff();
		cout << "Ëàìïà âûêëþ÷åíà" << endl;
	}
	void unExecute()
	{
		lamp->TurnOn();
		cout << "Ëàìïà âêëþ÷åíà" << endl;
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
			cout << "Îøèáêà! Íå÷åãî îòìåíÿòü" << endl;
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

