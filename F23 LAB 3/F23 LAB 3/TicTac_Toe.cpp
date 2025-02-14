#include <iostream>
#include "GameBoard.h"
#include "TicTac_Toe.h"
using namespace std;
void TicTacToe::playGame()
{
    GameBoard board;
    PlayerTurn currentPlayer;
    char player1Symbol, player2Symbol;

    cout << "Enter Player 1 Symbol: ";
    cin >> player1Symbol;
    cout << "Enter Player 2 Symbol: ";
    cin >> player2Symbol;

    srand(time(0));
    currentPlayer = (rand() % 2 == 0) ? SECOND_PLAYER : FIRST_PLAYER;
     
    while (board.getGameStatus() == IN_PROGRESS)
    {
        board.displayBoard();

        char currentPlayerSymbol = (currentPlayer == FIRST_PLAYER) ? player1Symbol : player2Symbol;
        cout << "\nPlayer " << currentPlayer << " Turn: Enter Cell #: ";
        int cellNumber;
        cin >> cellNumber;

        if (board.isValidPosition(cellNumber) && !board.isAlreadyMarked(cellNumber))
        {
            board.markBoard(cellNumber, currentPlayerSymbol);
            if (board.getGameStatus() != WIN)
            {
                currentPlayer == FIRST_PLAYER ? currentPlayer = SECOND_PLAYER : currentPlayer = FIRST_PLAYER;
            }
        }
        else
        {
            cout << "Invalid move. Please try again." << endl;
        }
    }
    if (board.getGameStatus() == WIN)
    {
        board.displayBoard();
        cout << "\nGame Won by Player: " << currentPlayer << endl;
    }
    else if (board.getGameStatus() == DRAW) {
        board.displayBoard();
        cout << "\nGame Draw" << endl;
    }
}
