#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <random>
#include <math.h>
#include <Windows.h>

#define Quiz4

using namespace std;

random_device rd;
mt19937 gen(rd());

#ifdef Quiz4
struct Card
{
	char type = '\0';
	bool exclude = false;
};

#endif // Quiz4

int main()
{
#ifdef Quiz4
	Card card[5][5];
	char command;

	uniform_int_distribution<int> randidx(0, 24);
	for (int i = 0; i < 25; ++i)
	{
		int x = randidx(gen);

		if (card[0][x].type == '\0')
		{
			if (i == 24)
				card[0][x].type = '@';
			else
				card[0][x].type = 'A' + i / 2;
		}
		else
			--i;
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << card[i][j].type << " ";
		}

		cout << endl;
	}

#endif // Quiz4

}