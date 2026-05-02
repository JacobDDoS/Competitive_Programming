#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

vector<vector<int>> v;

int bestPath(int row, int col) {
    if (row == v.size()-1) return v[row][col];
    return v[row][col] + max(bestPath(row+1, col), bestPath(row+1, col+1));
}

int main()
{
    // Since problem 67 is exactly the same with more rows, I'll leave the dp implementation to then and instead do brute force backtracking here;

    freopen("triangle.txt", "r", stdin);
    int num, cols = 1;
    while (cin >> num) {
        vector<int> row;
        row.push_back(num);
        for (int i=1;i<cols;i++) {
            cin >> num;
            row.push_back(num);
        }
        cols++;
        v.push_back(row);
    }

    cout << "The maximum total from top to bottom of the given triangle is " << bestPath(0, 0);

}