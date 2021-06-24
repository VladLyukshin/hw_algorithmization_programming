#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Game
{
private:
	int number_coins = 0;
	int number_farms = 0;
	mutex mt;

public:
	Game() {}

	void earn_coins()
	{
		while (true)
		{
			change_coins(1, "add");
			this_thread::sleep_for(chrono::seconds(3));
		}
	}

	void build_farm()
	{
		while (number_farms < 5)
		{
			if (number_coins >= 15)
			{
				change_coins(15, "sub");
				cout << "Farm is building" << endl;
				this_thread::sleep_for(std::chrono::seconds(60));
				number_farms += 1;
				cout << "Farm was finished" << endl;
				cout << "Current number of farms is " << number_farms << endl;
			}
		}
	}

	void change_coins(int number, string how)
	{
		mt.lock();
		if (how == "add")
		{
			number_coins++;
			cout << "+1 coin" << endl;
			cout << "Current number of coins is " << number_coins << endl;
		}
		else if (how == "sub")
		{
			number_coins -= 15;
			cout << "-15 coins" << endl;
			cout << "Current number of coins is " << number_coins << endl;
		}
		mt.unlock();
	}
};


int main()
{
	Game my_game;
	thread coins([&]() {my_game.earn_coins(); });
	coins.detach();
	thread farms([&]() {my_game.build_farm(); });
	farms.join();
	return 0;
}

