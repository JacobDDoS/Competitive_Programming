#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    vector<vector<ll>> grid(1001, vector<ll>(1001, 0));
    int dir = 2; // 1=up, 2=right, 3=down, 4=left
    int r=500, c=500;
    ll curNum = 1;
    while (c != 1001) {
        // cout << "r: " << r << ", c: " << c << ", dir: " << dir << endl;
        grid[r][c] = curNum;
        curNum++;
        if (dir == 1) {
            r--;
            if (r == c) dir = 2;
        } else if (dir == 2) {
            c++;
            if (curNum == 2 || ((1001-c)==r)) dir = 3;
        } else if (dir == 3) {
            r++;
            if (c == r) dir = 4;
        } else if (dir == 4) {
            c--;
            if (r == (1000-c)) dir = 1;
        }
    }

    ll ans = 0;
    r = 0, c = 0;
    while (c != 1001) {
        ans += grid[r][c];
        r++;
        c++;
    }
    r = 0, c = 1000;
    while (c != -1) {
        ans += grid[r][c];
        r++;
        c--;
    }
    ans -= grid[500][500];
    cout << "The sum of the numbers on the diagonals is " << ans << endl;
}