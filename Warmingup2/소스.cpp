#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <random>
#include <math.h>
#include <Windows.h>

#define Quiz5

using namespace std;

random_device rd;
mt19937 gen(rd());

#ifdef Quiz4
struct Card
{
	char type = '\0';
	bool exclude = false;
};

void DisplayBoard(Card card[][5])
{
	cout << "  a b c d e " << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << i + 1 << " ";

		for (int j = 0; j < 5; ++j)
		{
			if (card[i][j].exclude)
			{
				if(card[i][j].type != '@')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), int(card[i][j].type - 'A' + 1));
				cout << card[i][j].type << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
				cout << "* ";
		}

		cout << endl;
	}
}
#endif // Quiz4

int main()
{
#ifdef Quiz4
	Card card[5][5];
	char x1 = ' ', y1, x2, y2;

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

	while (x1 != 'q')
	{
		DisplayBoard(card);
		cout << "좌표 입력: ";
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 == 'r')
		{
			for (int i = 0; i < 25; ++i)
			{
				card[0][i].type = '\0';
				card[0][i].exclude = false;
			}

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
		}
		else if (x1 >= 'a' && x1 <= 'e' && y1 >= '1' && y1 <= '5'
			&& x2 >= 'a' && x2 <= 'e' && y2 >= '1' && y2 <= '5')
		{
			int row1 = x1 - 'a';
			int col1 = y1 - '1';
			int row2 = x2 - 'a';
			int col2 = y2 - '1';

			if (x1 == x2 && y1 == y2)
				cout << "동일한 좌표를 입력했습니다." << endl;
			else if (card[col1][row1].exclude || card[col2][row2].exclude)
				cout << "이미 개방된 카드입니다." << endl;
			else
			{
				card[col1][row1].exclude = true;
				card[col2][row2].exclude = true;

				DisplayBoard(card);

				if (card[col1][row1].type == '@')
				{
					for (int i = 0; i < 25; ++i)
					{
						if (card[0][i].type == card[col2][row2].type)
						{
							card[0][i].exclude = true;
							break;
						}
					}
				}
				else if (card[col2][row2].type == '@')
				{
					for (int i = 0; i < 25; ++i)
					{
						if (card[0][i].type == card[col1][row1].type)
						{
							card[0][i].exclude = true;
							break;
						}
					}
				}
				else if (card[col1][row1].type != card[col2][row2].type)
				{
					card[col1][row1].exclude = false;
					card[col2][row2].exclude = false;
				}
			}
		}
		else if(x1 != 'q')
			cout << "유효하지 않은 좌표 범위입니다." << endl;
		cout << endl;
	}

#endif // Quiz4

#ifdef Quiz5
	int left, top, right, bottom;
	char command = '\0';

	while (true)
	{
		cout << "좌표 입력: ";
		cin >> left >> top >> right >> bottom;
		if (!cin || left < 0 || top < 0 || right >= 30 || bottom >= 30)
		{
			cout << "유효하지 않은 좌표입니다." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else
			break;
	}

	while (command != 'q')
	{
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				if (j >= left && i >= top && j <= right && i <= bottom
					|| left > right && (j >= left || j <= right)
					|| top > bottom && (i >= top || i <= bottom))
					cout << "O ";
				else
					cout << ". ";
			}
			cout << endl;
		}

		cout << "명령어 입력: ";
		cin >> command;

		switch (command)
		{
		default:
			break;
		}
	}
#endif // Quiz5

}