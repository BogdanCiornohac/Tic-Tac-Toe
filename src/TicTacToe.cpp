#include "TicTacToe.h"
#include<iostream>
using namespace std;


TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			table[i][j] = '*';
	player[0] = 'X';
	player[1] = 'O';
	p = 0;
}
void TicTacToe::print_Table()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "| ";
		for (int j = 0; j < 3; j++)
			cout << table[i][j] << " | ";
		cout << '\n';

		if (i != 2)
			cout << "|---|---|---|";
		cout << '\n';
	}

}

void TicTacToe::clearTable()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			table[i][j] = '*';
	p = 0;
}

void TicTacToe::next_Player()
{
	if (p == 0)
		p++;
	else
		p--;
}

bool TicTacToe::isNotValidPlace(int x, int y)
{
	if (x > 2 || y > 2)
		return true;
	return false;
}



int TicTacToe::isNotWin()
{
	//searching on line if one of the two players won and return 1 if X won or -1 is O won
	for (int i = 0; i < 3; i++)
		if (table[i][0] == table[i][1] && table[i][0] == table[i][2] && table[i][0] != '*')
			if (table[i][0] == 'X')
				return 1;
			else
				return -1;
	//searching on column if one of the two players won and return 1 if X won or -1 is O won
	for (int i = 0; i < 3; i++)
		if (table[0][i] == table[1][i] && table[0][i] == table[2][i] && table[0][i] != '*')
			if (table[0][i] == 'X')
				return 1;
			else
				return -1;
	//searching on diagonal if one of the two players won and return 1 if X won or -1 is O won
	if (table[0][0] != '*' && table[0][0] == table[1][1] && table[0][0] == table[2][2])
		if (table[0][0] == 'X')
			return 1;
		else
			return -1;
	if (table[0][2] != '*' && table[0][2] == table[1][1] && table[0][2] == table[2][0])
		if (table[0][2] == 'X')
			return 1;
		else
			return -1;
	//return 0 is if a tie or nobody won
	return 0;
}

void TicTacToe::playVsPlayer()
{
	system("cls");
	print_Table();
	int x, y;
	int moves = 9, win = 0;
	char answer;
	while (moves && win == 0)
	{
		cout << "It's player " << player[p] << " time to choose a position! Insert row and column: ";
		cin >> x >> y;

		while (isNotValidPlace(x, y) || table[x][y] != '*')
		{
			validation(x, y);
			cin >> x >> y;
		}
		table[x][y] = player[p];
		next_Player();
		system("cls");
		print_Table();
		win = isNotWin();
		moves--;

	}
	next_Player();
	if (isNotWin() != 0)
		cout << "Congratulations! Player " << player[p] << " wins :-) !\n";
	else
		cout << "It's a tie!\n";
	cout << "Would you like to play again? y/n\n";
	cin >> answer;
	if (answer == 'y')
	{
		cout << '\n';
		replayVsPlayer();
	}
}

void TicTacToe::replayVsPlayer()
{
	clearTable();
	playVsPlayer();
}

void TicTacToe::replayVsAi()
{
	clearTable();
	playVsAi();
}

void TicTacToe::menu()
{
	int mode;
	cout << "  Welcome to Tic Tac Toe :-P !! \n Choose the mode of the game: \n  1. Vs player.\n  2. Vs AI.\n";
	cin >> mode;
	if (mode == 1)
		playVsPlayer();
	else
		playVsAi();

}

void TicTacToe::playVsAi()
{
	system("cls");
	print_Table();
	int x, y;
	int moves = 9, win = 0;
	char answer;
	while (moves && win == 0)
	{
		if (p == 1)
		{
			cout << "It's your time! Insert row and column: ";
			cin >> x >> y;
			while (isNotValidPlace(x, y) || table[x][y] != '*')
			{
				validation(x, y);
				cin >> x >> y;
			}
			table[x][y] = player[p];
		}
		else {
			aiTurn();
		}
		next_Player();
		system("cls");
		win = isNotWin();
		print_Table();
		moves--;


	}
	next_Player();
	if (isNotWin() != 0)
		cout << "Congratulations! Player " << player[p] << " wins :-) !\n";
	else
		cout << "It's a tie!\n";
	cout << "Would you like to play again? y/n\n";
	cin >> answer;
	if (answer == 'y')
	{
		cout << '\n';
		replayVsAi();
	}
}

void TicTacToe::validation(int x, int y)
{
	if (isNotValidPlace(x, y))
		cout << "Wrong coordinates! Please insert again: ";
	else
		cout << "This position is already used! Please insert again: ";
}

void TicTacToe::aiTurn()
{
	struct Ai
	{
		int x, y;
	}ai;
	int bestScore = -100, score;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (table[i][j] == '*')
			{
				table[i][j] = 'X';
				score = miniMax(0);
				table[i][j] = '*';
				if (score > bestScore)
				{
					bestScore = score;
					ai.x = i;
					ai.y = j;
				}
			}
		}
	table[ai.x][ai.y] = 'X';
}

int TicTacToe::miniMax(bool isMaximizing)
{
	int rez = isNotWin();
	if (rez != NULL)
		return rez;
	if (isMaximizing)
	{
		int bestScore = -100;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == '*')
				{
					table[i][j] = 'X';
					int score = miniMax(0);
					table[i][j] = '*';
					bestScore = max(score, bestScore);
				}
			}
		}
		return bestScore;
	}
	else
	{
		int bestScore = 100;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == '*')
				{
					table[i][j] = 'O';
					int score = miniMax(1);
					table[i][j] = '*';
					bestScore = min(score, bestScore);
				}
			}
		}
		return bestScore;
	}
}