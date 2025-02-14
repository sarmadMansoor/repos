//#include <iostream>
//#include <iomanip>
//#include <ctime>
//
//using namespace std;
//
//enum PlayerTurn { FIRST_PLAYER = 1, SECOND_PLAYER = 2 };
//enum GameStatus { DRAW, WIN, IN_PROGRESS };
//
//class GameBoard
//{
//private:
//    char data[3][3][3];
//    GameStatus gameStatus;
//    int validMovesCount;
//
//public:
//    GameBoard()
//    {
//        for (int i = 0; i < 3; ++i) 
//        {
//            for (int j = 0; j < 3; ++j)
//            {
//                for (int k = 0; k < 3; ++k)
//                {
//                    data[i][j][k] = '.';
//                }
//            }
//        }
//        gameStatus = IN_PROGRESS;
//        validMovesCount = 0;
//    }
//
//    void displayBoard() 
//    {
//        for (int i = 0; i < 3; ++i)
//        {
//            for (int j = 0; j < 3; ++j) 
//            {
//                for (int k = 0; k < 3; ++k)
//                {
//                    cout << setw(3) << data[i][j][k] << " ";
//                }
//                cout << "\t";
//            }
//            cout << endl;
//        }
//    }
//
//    void markBoard(int pos, char playerSymbol)
//    {
//        int plane = (pos - 1) / 9;
//        int row = ((pos - 1) % 9) / 3;
//        int col = ((pos - 1) % 9) % 3;
//
//        data[plane][row][col] = playerSymbol;
//        validMovesCount++;
//
//        if (checkWin(playerSymbol, plane, row, col))
//            gameStatus = WIN;
//        else if (validMovesCount == 27)
//            gameStatus = DRAW;
//    }
//
//    bool isValidPosition(int pos) {
//        return pos >= 1 && pos <= 27;
//    }
//
//    bool isAlreadyMarked(int pos) {
//        int plane = (pos - 1) / 9;
//        int row = ((pos - 1) % 9) / 3;
//        int col = ((pos - 1) % 9) % 3;
//
//        return data[plane][row][col] != '.';
//    }
//
//    int getValidMovesCount() {
//        return validMovesCount;
//    }
//
//    GameStatus getGameStatus() {
//        return gameStatus;
//    }
//
//private:
//    bool checkWin(char playerSymbol, int plane, int row, int col) {
//        // Check rows and columns in current plane
//        for (int i = 0; i < 3; ++i) {
//            if (data[plane][row][i] != playerSymbol)
//                break;
//            if (i == 2) return true;
//
//            if (data[plane][i][col] != playerSymbol)
//                break;
//            if (i == 2) return true;
//        }
//
//        // Check diagonal in current plane
//        if (plane == 0 || plane == 2) 
//        {
//            if ((data[plane][0][0] == playerSymbol && data[plane][1][1] == playerSymbol && data[plane][2][2] == playerSymbol) ||
//                (data[plane][0][2] == playerSymbol && data[plane][1][1] == playerSymbol && data[plane][2][0] == playerSymbol))
//                return true;
//        }
//
//        // Check diagonals across planes
//        if ((data[0][row][col] == playerSymbol && data[1][row][col] == playerSymbol && data[2][row][col] == playerSymbol) ||
//            (plane == row && data[0][0][col] == playerSymbol && data[1][1][col] == playerSymbol && data[2][2][col] == playerSymbol) ||
//            (plane == row && data[0][2][col] == playerSymbol && data[1][1][col] == playerSymbol && data[2][0][col] == playerSymbol) ||
//            (plane == col && data[0][row][0] == playerSymbol && data[1][row][1] == playerSymbol && data[2][row][2] == playerSymbol) ||
//            (plane == col && data[0][row][2] == playerSymbol && data[1][row][1] == playerSymbol && data[2][row][0] == playerSymbol))
//            return true;
//
//        return false;
//    }
//};
//
//class TicTacToe {
//public:
//    void playGame() 
//    {
//        GameBoard board;
//        PlayerTurn currentPlayer;
//        char player1Symbol, player2Symbol;
//
//        cout << "Enter Player 1 Symbol: ";
//        cin >> player1Symbol;
//        cout << "Enter Player 2 Symbol: ";
//        cin >> player2Symbol;
//
//        srand(time(nullptr));
//        currentPlayer = (rand() % 2 == 0) ? FIRST_PLAYER : SECOND_PLAYER;
//
//        while (board.getGameStatus() == IN_PROGRESS) {
//            board.displayBoard();
//
//            char currentPlayerSymbol = (currentPlayer == FIRST_PLAYER) ? player1Symbol : player2Symbol;
//            cout << "\nPlayer " << currentPlayer << " Turn: Enter Cell #: ";
//            int cellNumber;
//            cin >> cellNumber;
//
//            if (board.isValidPosition(cellNumber) && !board.isAlreadyMarked(cellNumber)) {
//                board.markBoard(cellNumber, currentPlayerSymbol);
//                currentPlayer = (currentPlayer == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER;
//            }
//            else {
//                cout << "Invalid move. Please try again." << endl;
//            }
//        }
//
//        if (board.getGameStatus() == WIN) {
//            board.displayBoard();
//            cout << "\nGame Won by Player: " << currentPlayer << endl;
//        }
//        else if (board.getGameStatus() == DRAW) {
//            board.displayBoard();
//            cout << "\nGame Draw" << endl;
//        }
//    }
//};
//
//int main() 
//{
//    TicTacToe tic;
//    tic.playGame();
//}


#include <iostream>
#include "GameBoard.h"
#include "TicTac_Toe.h"
using namespace std;


int main() {
    TicTacToe tic;
    tic.playGame();
}
