#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame_Classes.h"
using namespace std;

// Set the board
Tic_Tac_Toe_Board::Tic_Tac_Toe_Board () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Tic_Tac_Toe_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = mark;
        n_moves++;
        return true;
    }
    else
        return false;
}


// Display the board and the pieces on it
void Tic_Tac_Toe_Board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n--------------------------------------------------";
    }
    cout << endl;
}

bool Tic_Tac_Toe_Board:: is_winner(){
    int X_Counter = 0; int O_Counter = 0;

    //check rows
    for(int i = 0; i < 5; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if(board[i][0] == 'X'){
                X_Counter++;
                cout << "X-" ;
                cout << i << "," << 0 << " " << i << "," <<1 << " " << i << "," << 2<< endl;
            }
            else if(board[i][0] == 'O'){
                O_Counter++;
                cout << "Y-";
                cout << i << "," << 0 << " " << i << "," <<1 << " " << i << "," << 2<< endl;
            }
        }
        if(board[i][1] == board[i][2] && board[i][1] == board[i][3])
        {
            if(board[i][1] == 'X'){
                X_Counter++;
                cout << "X-" ;
                cout << i << "," << 1 << " " << i << "," <<2 << " " << i << "," << 3<< endl;
            }
            else if(board[i][1] == 'O'){
                O_Counter++;
                cout << "Y-";
                cout << i << "," << 1 << " " << i << "," <<2 << " " << i << "," << 3<< endl;
            }
        }
        if(board[i][2] == board[i][3] && board[i][2] == board[i][4])
        {
            if(board[i][2] == 'X'){
                X_Counter++;
                cout << "X-" ;
                cout << i << "," << 2 << " " << i << "," << 3 << " " << i << "," << 4 << endl;
            }
            else if(board[i][2] == 'O'){
                O_Counter++;
                cout << "Y-";
                cout << i << "," << 2 << " " << i << "," << 3 << " " << i << "," << 4 << endl;
            }
        }
    }

    //check columns
    for(int i = 0; i < 5; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            if(board[0][i] == 'X'){
                X_Counter++;
                cout << "X-" ;
                cout << 0 << "," << i << " " << 1 << "," <<i << " " << 2 << "," << i<< endl;
            }
            else if(board[0][i] == 'O'){
                O_Counter++;
                cout << "Y-";
                cout << 0 << "," << i << " " << 1 << "," <<i << " " << 2 << "," << i<< endl;
            }
        }
        if(board[1][i] == board[2][i] && board[1][i] == board[3][i])
        {
            if(board[1][i] == 'X'){
                X_Counter++;
                cout << "X-" ;
                cout << 1 << "," << i << " " << 2 << "," <<i << " " << 3 << "," << i<< endl;
            }
            else if(board[1][i] == 'O'){
                O_Counter++;
                cout << "Y-";
                cout << 1 << "," << i << " " << 2 << "," <<i << " " << 3 << "," << i<< endl;
            }
        }
        if(board[2][i] == board[3][i] && board[2][i] == board[4][i])
        {
            if(board[2][i] == 'X'){
                X_Counter++;
                cout << "X-" ;
                cout << 2 << "," << i << " " << 3 << "," << i << " " << 4 << "," << i<< endl;
            }
            else if(board[2][i] == 'O'){
                O_Counter++;
                cout << "Y-";
                cout << 2 << "," << i << " " << 3 << "," << i << " " << 4 << "," << i<< endl;
            }
        }
    }


    //check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        if(board[0][0] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 0 << "," << 0 << " " << 1 << "," <<1 << " " << 2 << "," << 2<< endl;
        }
        else if(board[0][0] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 0 << "," << 0 << " " << 1 << "," <<1 << " " << 2 << "," << 2<< endl;
        }
    }
    if(board[1][1] == board[2][2] && board[1][1] == board[3][3]){
        if(board[1][1] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 1 << "," << 1 << " " << 2 << "," << 2 << " " << 3 << "," << 3<< endl;
        }
        else if(board[1][1] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 1 << "," << 1 << " " << 2 << "," << 2 << " " << 3 << "," << 3<< endl;
        }
    }
    if(board[2][2] == board[3][3] && board[2][2] == board[4][4]){
        if(board[2][2] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 2 << "," << 2 << " " << 3 << "," << 3 << " " << 4 << "," << 4<< endl;
        }
        else if(board[2][2] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 2 << "," << 2 << " " << 3 << "," << 3 << " " << 4 << "," << 4<< endl;
        }
    }
    if(board[0][1] == board[1][2] && board[0][1] == board[2][3]){
        if(board[0][1] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 0 << "," << 1 << " " << 1 << "," <<2 << " " << 2 << "," << 3<< endl;
        }
        else if(board[0][1] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 0 << "," << 1 << " " << 1 << "," <<2 << " " << 2 << "," << 3<< endl;

        }
    }
    if(board[1][2] == board[2][3] && board[1][2] == board[3][4]){
        if(board[1][2] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 1 << "," << 2 << " " << 2 << "," <<3 << " " << 3 << "," << 4<< endl;
        }
        else if(board[1][2] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 1 << "," << 2 << " " << 2 << "," <<3 << " " << 3 << "," << 4<< endl;
        }
    }
    if(board[0][2] == board[1][3] && board[0][2] == board[2][4]){
        if(board[0][2] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 0 << "," << 2 << " " << 1 << "," <<3 << " " << 2 << "," << 4<< endl;
        }
        else if(board[0][2] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 0 << "," << 2 << " " << 1 << "," <<3 << " " << 2 << "," << 4<< endl;
        }
    }

    if(board[1][0] == board[2][1] && board[1][0] == board[3][2]){
        if(board[1][0] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 1 << "," << 0 << " " << 2 << "," <<1 << " " << 3 << "," << 2<< endl;
        }
        else if(board[1][0] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 1 << "," << 0 << " " << 2 << "," <<1 << " " << 3 << "," << 2<< endl;
        }
    }
    if(board[2][1] == board[3][2] && board[2][1] == board[4][3]){
        if(board[2][1] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 2 << "," << 1 << " " << 3 << "," << 2 << " " << 4 << "," << 3<< endl;
        }
        else if(board[2][1] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 2 << "," << 1 << " " << 3 << "," << 2 << " " << 4 << "," << 3<< endl;
        }
    }
    if(board[2][0] == board[3][1] && board[2][0] == board[4][2]){
        if(board[2][0] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 2 << "," << 0 << " " << 3 << "," <<1 << " " << 4 << "," << 2<< endl;
        }
        else if(board[2][0] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 2 << "," << 0 << " " << 3 << "," <<1 << " " << 4 << "," << 2<< endl;
        }
    }

    // In the opposite direction (diogonals)
    if(board[0][4] == board[1][3] && board[0][4] == board[2][2]){
        if(board[0][4] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 0 << "," << 4 << " " << 1 << "," <<3 << " " << 2 << "," << 2<< endl;
        }
        else if(board[0][4] == 'O'){
            O_Counter++;
            cout << "Y- ";
            cout << 0 << "," << 4 << " " << 1 << "," <<3 << " " << 2 << "," << 2<< endl;
        }
    }
    if(board[1][3] == board[2][2] && board[1][3] == board[3][1]){
        if(board[1][3] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 1 << "," << 3 << " " << 2 << "," <<2 << " " << 3 << "," << 1<< endl;
        }
        else if(board[1][3] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 1 << "," << 3 << " " << 2 << "," <<2 << " " << 3 << "," << 1<< endl;
        }
    }
    if(board[2][2] == board[3][1] && board[2][2] == board[4][0]){
        if(board[2][2] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 2 << "," << 2 << " " << 3 << "," <<1 << " " << 4 << "," << 0<< endl;
        }
        else if(board[2][2] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 2 << "," << 2 << " " << 3 << "," <<1 << " " << 4 << "," << 0<< endl;
        }
    }

    if(board[0][3] == board[1][2] && board[0][3] == board[2][1]){
        if(board[0][3] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 0 << "," << 3 << " " << 1 << "," << 2 << " " << 2 << "," << 1<< endl;
        }
        else if(board[0][3] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 0 << "," << 3 << " " << 1 << "," << 2 << " " << 2 << "," << 1<< endl;
        }
    }
    if(board[1][2] == board[2][1] && board[1][2] == board[3][0]){
        if(board[1][2] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 1 << "," << 2 << " " << 2 << "," <<1 << " " << 3 << "," << 0<< endl;
        }
        else if(board[1][2] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 1 << "," << 2 << " " << 2 << "," <<1 << " " << 3 << "," << 0<< endl;
        }
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        if(board[0][2] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 0 << "," << 2 << " " << 1 << "," <<1 << " " << 2 << "," << 0<< endl;
        }
        else if(board[0][2] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 0 << "," << 2 << " " << 1 << "," <<1 << " " << 2 << "," << 0<< endl;
        }
    }

    if(board[1][4] == board[2][3] && board[1][4] == board[3][2]){
        if(board[1][4] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 1 << "," << 4 << " " << 2 << "," <<3 << " " << 3 << "," << 2<< endl;
        }
        else if(board[1][4] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 1 << "," << 4 << " " << 2 << "," <<3 << " " << 3 << "," << 2<< endl;
        }
    }
    if(board[2][3] == board[3][2] && board[2][3] == board[4][1]){
        if(board[2][3] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 2 << "," << 3 << " " << 3 << "," << 2 << " " << 4 << "," << 1 << endl;
        }
        else if(board[2][3] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 2 << "," << 3 << " " << 3 << "," << 2 << " " << 4 << "," << 1 << endl;
        }
    }
    if(board[2][4] == board[3][3] && board[2][4] == board[4][2]){
        if(board[2][4] == 'X'){
            X_Counter++;
            cout << "X-" ;
            cout << 2 << "," << 4 << " " << 3 << "," << 3 << " " << 4 << "," << 2<< endl;
        }
        else if(board[2][4] == 'O'){
            O_Counter++;
            cout << "Y-";
            cout << 2 << "," << 4 << " " << 3 << "," << 3 << " " << 4 << "," << 2<< endl;
        }
    }

    if(X_Counter == O_Counter){
        cout << "It's a tie!" << endl;
        cout << "There is no winner" << endl;
        cout << "X Counter: " << X_Counter << endl;
        cout << "O Counter: " << O_Counter << endl;
        return false;
    }
    else if(X_Counter > O_Counter){
        cout << "X Wins!" << endl;
        cout << "X Counter: " << X_Counter << endl;
        cout << "O Counter: " << O_Counter << endl;
        return true;
    }
    else{
        cout << "Y Wins!" << endl;
        cout << "X Counter: " << X_Counter << endl;
        cout << "O Counter: " << O_Counter << endl;
        return true;
    }
}

// Return true if 24 moves are done and no winner
bool Tic_Tac_Toe_Board::is_draw() {
    return (n_moves == 24 && !is_winner());
}

bool Tic_Tac_Toe_Board::game_is_over() {
    return n_moves >= 24;
}

