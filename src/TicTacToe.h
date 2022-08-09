#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

class TicTacToe
{
private:
	char table[3][3];
	char player[2];
	int  playerTurn;

public:
	//Constructor
	TicTacToe();
	//Print the table of the game
	void printTable();
	//Start  game against another player
	void playVsPlayer();
	//Start a new game against AI
	void playVsAi();
	//Switch turn to next player
	void nextPlayer();
	//Check if someone won
	int hasWon();
	//Clear the table for a new round of the game
	void clearTable();
	//Create the meniu of the game
	void menu();
	//Check if coordonites or position are avalabile
	void validation(int x, int y);
	//Choose AI position
	void aiTurn();
	//Search the best move for AI
	int miniMax(bool isMaximazing);
	//Replay the game against player
	void replayVsPlayer();
	//Replay the game against AI
	void replayVsAi();

};

#endif