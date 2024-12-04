  #include <iostream>
#include <string>
using namespace std;

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    }; // Creates a two-dimensional array for the board
    
    const char playerX = 'X'; // Creating players
    const char playerO = 'O';
    char currentplayer = playerX;
    
    int r = -1, c = -1; // Input variables
    char winner = ' ';  // Winner variable
    
    // Printing the board and taking moves up to 9 times
    for (int i = 0; i < 9; i++) {
        // Display the board
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;
        
        if (winner != ' ') { // If there's a winner, break the loop
            break;
        }

        cout << "Current player is " << currentplayer << endl;

        // Checking for valid inputs
        while (true) {
            cout << "Enter row and column number from 0-2: ";
            cin >> r >> c;

            if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Enter a valid position." << endl;
            } else if (board[r][c] != ' ') {
                cout << "Tile is full, try again." << endl;
            } else {
                break;
            }

            // Clear and ignore invalid input
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Assigning input places to the player
        board[r][c] = currentplayer;
        currentplayer = (currentplayer == playerX) ? playerO : playerX;

        // Checking for a winner in rows
        for (int row = 0; row < 3; row++) {
            if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                winner = board[row][0];
                break;
            }
        }

        // Checking for a winner in columns
        for (int col = 0; col < 3; col++) {
            if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                winner = board[0][col];
                break;
            }
        }

        // Checking for a winner in diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }

        // If we have a winner, announce it and exit loop
        if (winner != ' ') {
            cout << "Player " << winner << " is the winner!" << endl;
            break;
        }
    }

    // If there's no winner after 9 moves, it's a tie
    if (winner == ' ') {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
