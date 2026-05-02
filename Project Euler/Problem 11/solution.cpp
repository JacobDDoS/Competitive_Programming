#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    freopen("grid.txt", "r", stdin);
    vector<vector<int>> v(20, vector<int>(20, 0));
    for (int i=0;i<20;i++) {
        for (int j=0;j<20;j++) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int r=0;r<20;r++) {
        for (int c=0;c<20;c++) {
            // right
            if (c <= 16) {
                ans = max(ans, v[r][c]*v[r][c+1]*v[r][c+2]*v[r][c+3]);
            }
            // down
            if (r <= 16) {
                ans = max(ans, v[r][c]*v[r+1][c]*v[r+2][c]*v[r+3][c]);
            }
            // right-down diagonal
            if (c <= 16 && r <= 16) {
                ans = max(ans, v[r][c]*v[r+1][c+1]*v[r+2][c+2]*v[r+3][c+3]);
            }

            // left-down diagonal
            if (c >= 3 && r <= 16) {
                ans = max(ans, v[r][c]*v[r+1][c-1]*v[r+2][c-2]*v[r+3][c-3]);
            }
        }
    }
    cout << "Maximum product of 4 consecutive numbers is " << ans << endl;
}