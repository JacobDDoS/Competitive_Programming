// Author: JacobDDoS 
// Date: 10/4/22
// Problem: N x N Queens 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

int queens;
ull ans = 0;

//Board for N x N Queens
vector<vector<bool>> board;

//Create column and diagonal bool arrays (to keep check to whether or not they are occupied)
vector<bool> colArr;

//Starts from top left and increases as it goes down or right
vector<bool> diag1Arr;

//Starts from bottom left and increases as it goes right or left
vector<bool> diag2Arr;

void NxNQueens(int row, int col) {
    for (int curCol=0;curCol<queens;curCol++) {
        if (row != queens && !colArr[curCol] && !diag1Arr[row+curCol] && !diag2Arr[queens-row-1+curCol]) {
            //Set next column & diagonals to be true
            colArr[curCol] = true;
            diag1Arr[row+curCol] = true;
            diag2Arr[queens-row-1+curCol] = true;
            NxNQueens(row+1, curCol);
            colArr[curCol] = false;
            diag1Arr[row+curCol] = false;
            diag2Arr[queens-row-1+curCol] = false;
        } else if (row == queens) {
            ans++;
            return;
        }
    }
}

void solve(int n) {
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (n < 4) {
        cout << "0\n";
        return;
    }

    //Create board
    vector<bool> row(n, false);
    for (int i=0;i<n;i++) {
        board.push_back(row);
    }

    //Create column & diagonal tables
    for (int i=0;i<n;i++) {
        colArr.push_back(false);
    }

    for (int i=0;i<2*n-1;i++) {
        diag1Arr.push_back(false);
        diag2Arr.push_back(false);
    }

    //Start algorithm
    ans = 0;
    for (int i=0;i<n;i++) {
        NxNQueens(0, i);
    }

    cout << ans/queens << '\n';

}

int main() {
    cin >> queens;
    solve(queens);
}