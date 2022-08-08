#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

class TicTacToe
{
private:
	char table[3][3];
	char player[2];
	int  p;

public:
	TicTacToe();
	void print_Table();
	void playVsPlayer();
	void playVsAi();
	void next_Player();
	bool isNotValidPlace(int x, int y);
	int isNotWin();
	void clearTable();
	void replayVsPlayer();
	void menu();
	void validation(int x, int y);
	void aiTurn();
	int miniMax(bool isMaximazing);
	void replayVsAi();

};

#endif