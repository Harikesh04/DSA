#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/sudoku-solver/?envType=list&envId=r2zzj5c3

class Solution {
public:
    int N=0;

    // Approach:

    // here we are using simple backtracking approach
    // firstly finding the blank block in the box and try to insert the number
    // the check if isSafe true if true then do furture call else backtrack.

    bool isSafe(int row, int col, int num, vector<vector<char>>& board) {
    // if num is already present in the same row or col
    for (int i = 0; i < N; i++) {
        if (board[row][i] == (num + '0') || board[i][col] == (num + '0')) return false;
    }

    // check if the number is already present in the grid of size sqrt(N) or not

    // here we have to find start kha se krna h(row,col)

    int n = sqrt(N);
    int g_start_row = row - row % n;
    int g_start_col = col - col % n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[g_start_row + i][g_start_col + j] == num + '0') return false;
        }
    }

    return true;
}


    bool solve(vector<vector<char>>& board) {
    // Searching for empty box from current cell (i, j)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '.') {
                for (int num = 1; num <= N; num++) {
                    if (isSafe(i, j, num, board)) {
                        board[i][j] = num + '0';
                        if (solve(board)) return true;
                        board[i][j] = '.'; // Backtrack
                    }
                }
                return false; // No valid number found for this cell
            }
        }
    }

    return true; // All cells are filled
}

    void solveSudoku(vector<vector<char>>& board) {
        N=board.size();
        

        solve(board);

       


        
    }
};