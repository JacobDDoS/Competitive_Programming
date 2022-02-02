// Author: JacobDDoS 
// Date: 2/1/22
// Problem: NEKO's Maze Game

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;
int n;
bool isOpen(int r, int c, vector<vector<bool>>& state) {
    if ((r==1&&c==0)||(r==2&&c==2*n-1)) return false;
    if (r == 1) {
        if (c==2*n-1) return !(state[1][c-1]);
        if (c==2*n-2) return !(state[1][c] || state[1][c-1]); 
        return !(state[1][c-1] || state[1][c] || state[1][c+1]);
    } else {
        if (c==0) return !(state[0][1]);
        if (c==1) return !(state[0][1] || state[0][2]);
        return !(state[0][c-1] || state[0][c] || state[0][c+1]);
    }
}

void solve() {
    int q; cin >> n >> q;
    bool isPossible = true;
    vector<vector<bool>> states(2, vector<bool>(2*n));
    set<pair<int,int>> stuck;
    for (int i=0;i<q;i++) {
        int r, c; cin >> r >> c;
        states[r-1][c-1] = !states[r-1][c-1];
        if (!isOpen(r, c-1, states) && !isOpen(r^3, c-1, states)) {
            isPossible = false;
            stuck.insert(make_pair(r, c));
        } else {
            while (stuck.size()) {
                pair<int, int> pr = *stuck.lower_bound(make_pair(0, 0));
                if (isOpen(pr.first, pr.second-1, states) || isOpen(pr.first^3, pr.second-1, states)) {
                    stuck.erase(pr);
                } else {
                    break;
                }
            }
            if (!stuck.size()) {
                isPossible = true;
            }
        }
        if (isPossible) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}