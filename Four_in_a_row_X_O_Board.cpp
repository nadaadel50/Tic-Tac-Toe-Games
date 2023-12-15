#include <iostream>
#include <iomanip>
#include <algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

Four_in_a_row_X_O_Board::Four_in_a_row_X_O_Board() {
    n_rows =6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }

}
bool Four_in_a_row_X_O_Board::update_board(int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
        if(x==5){
            board[5][y]=toupper(mark);
            n_moves++;
            return true;
        }
        else{
            for (int i = 1; i < 6; ++i) {
                if (board[x + i][y] != 0) {
                    board[x+i-1][y] = toupper(mark);
                    n_moves++;
                    return true;
                }
                else if ((i == 5 && board[x + i][y] == 0)||x+i==5 && board[x + i][y]==0) {
                    board[5][y] = toupper(mark);
                    n_moves++;
                    return true;
                }
            }
        }

    }
}
void Four_in_a_row_X_O_Board::display_board(){
    for (int i: {0,1,2,3,4,5}) {  //row
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {   //column
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n------------------------------------------------------------------";
    }
    cout << endl;
}
bool Four_in_a_row_X_O_Board::is_winner(){
    char row_win[6][4], col_win[3][7], diag_win[3][7];
    for (int i:{0,1,2,3,4,5}) {
        for (int j:{0,1,2,3}) {
            row_win[i][j] = board[i][j] & board[i][j+1] & board[i][j+2]&board[i][j+3];
        }
    }

    for (int i:{0,1,2,3,4,5,6}) {
        for (int j:{0,1,2}) {
            col_win[j][i] = board[j][i] & board[j+1][i] & board[j+2][i]&board[j+3][i];
        }
    }

    for(int i:{0,1,2}) {
        for  (int j = 0; j <4 ; ++j)    {
            diag_win[i][j] = board[i][j] & board[i+1][j+1] & board[i+2][j+2]& board[i+3][j+3];
        }
    }
    for(int i:{0,1,2}) {
        for  (int j = 3; j <7 ; ++j)    {
            diag_win[i][j+1] = board[i][j] & board[i+1][j-1] & board[i+2][j-2]& board[i+3][j-3];
        }
    }

    for (int i:{0,1,2,3,4,5}) {
         for (int j:{0,1,2,3}) {
             if(row_win[i][j] && row_win[i][j]==board[i][j+1]){
                 return true;
             }
        }
    }
    for (int i:{0,1,2,3,4,5,6}) {
        for (int j:{0,1,2}) {
            if(col_win[j][i] && col_win[j][i]==board[j+1][i]){
                return true;
            }
        }
    }

    for(int i = 0; i <3 ; ++i) {
        for  (int j = 0; j <4 ; ++j)    {
           if(diag_win[i][j] && diag_win[i][j] == board[i+1][j+1]){
               return true;
           }
        }
        for  (int j = 3; j <7 ; ++j)    {
            if(diag_win[i][j+1] && diag_win[i][j] == board[i+1][j-1]){
                return true;
            }
        }

    }

}
bool Four_in_a_row_X_O_Board::is_draw(){
    return (n_moves == 42 && !is_winner());
}

bool Four_in_a_row_X_O_Board::game_is_over(){
    return n_moves >= 42;

}

