#include<iostream>
#include "GameBoard.h"
using namespace std;
void GameBoard::updateGameStatus()
{
	int planeNumber = 0;
	while (planeNumber <= 2)
	{
		if (checkBoard(planeNumber))
		{
			gameStatus = WIN;
			return;
		}
		planeNumber++;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)   
		{
			if ((data[0][i][j] < '1') || (data[0][i][j] > '9'))
			{
				if (data[0][i][j] == data[1][i][j] && data[1][i][j] == data[2][i][j])
				{
					gameStatus = WIN;
					return;
				}
			}
		}
	}
	validMovesCount == 27 ? gameStatus = DRAW : gameStatus;
}
bool GameBoard::checkBoard(int board)
{
	bool winStatus = false;
	if  ((data[board][0][0] == data[board][1][0] && data[board][1][0] == data[board][2][0]) || (data[board][0][0] == data[board][0][1] && data[board][0][1] == data[board][0][2]))
	{
		winStatus = true;
	}
	else if ((data[board][0][0] == data[board][1][1] && data[board][1][1] == data[board][2][2]) || (data[board][0][2] == data[board][1][1] && data[board][1][1] == data[board][2][0]) || (data[board][1][0] == data[board][1][1] && data[board][1][1] == data[board][1][2]) || (data[board][0][1] == data[board][1][1] && data[board][1][1] == data[board][2][2]))
	{
		winStatus = true;
	}
	else if ((data[board][2][2] == data[board][1][2] && data[board][1][2] == data[board][0][2]) || (data[board][2][2] == data[board][2][1] && data[board][2][1] == data[board][2][0]))
	{
		winStatus = true;
	}
	return winStatus;
}
GameBoard::GameBoard()
{
	char num = '1';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <3; j++)
		{
			for (int k = 0; k <3; k++)
			{
				data[i][j][k] = num;
				num++;
			}
		}
		num = '1';
	}
}
void GameBoard::displayBoard()
{
	cout << '\n';
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)  
		{
			cout << "\t";
			for (int j = 0; j < 3; j++)
			{
				cout << data[k][i][j] << "  ";
			}
		}
		cout << '\n';
	}
	cout << "      -----------     -----------     -----------\n\t   1\t\t   2\t\t   3\n";
}
void GameBoard::markBoard(int pos, char playerSymbol)
{
	int board = pos / 10 - 1;
	int row = (pos % 10 - 1) / 3;
	int col = (pos % 10 - 1) % 3;
	data[board][row][col] = playerSymbol;
	validMovesCount++;
	updateGameStatus();
}
bool GameBoard::isValidPosition(int pos)
{
	if ((pos / 10) < 1 || (pos / 10) > 3)
		return false;
	if ((pos % 10) >= 1 && (pos % 10) <= 9)
	{
		return true;
	}
	return false;
}
bool GameBoard::isAlreadyMarked(int pos)
{
	int board = pos / 10 - 1;
	int row = (pos % 10 - 1) / 3;
	int col = (pos % 10 - 1) % 3;

	if (data[board][row][col] >= '1' && data[board][row][col] <= '9')
	{
		return false;
	}
	else
	{
		return true;
	}
}
int GameBoard::getValidMovesCount()
{
	return validMovesCount;
}

GameStatus GameBoard::getGameStatus()
{
	return gameStatus;
}
