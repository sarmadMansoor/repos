#ifndef GAME_BOARD_H
#define GAME_BOARD_H
enum PlayerTurn { FIRST_PLAYER = 1, SECOND_PLAYER = 2 };
enum GameStatus { DRAW, WIN, IN_PROGRESS };
class GameBoard
{
private:
	char data[3][3][3];
	GameStatus gameStatus = IN_PROGRESS;
	int validMovesCount = 0; 
	bool checkBoard(int board);
	void updateGameStatus();
public:
	GameBoard();
	void displayBoard();
	void markBoard(int   pos, char playerSymbol);
	bool isValidPosition(int  pos);
	bool isAlreadyMarked(int pos);
	int getValidMovesCount();
	GameStatus getGameStatus();
};

#endif 

