#include <bits/stdc++.h>
using namespace std;

string laser(vector<string>& grid, vector<vector<bool>>& visited, int r, int c, int dir) {
    // cout << "r: " << r << " c: " << c << " dir: " << dir << endl;
    if (r >= (int)grid.size()) {
        return ("S"+to_string(c+1)+ " ");
    } else if (r < 0) {
        return ("N"+to_string(c+1)+ " ");
    } else if (c >= (int)grid[0].size()) {
        return ("E"+to_string(r+1)+ " ");
    } else if (c < 0) {
        return ("W"+to_string(r+1)+" ");
    }

    visited[r][c] = true;
    if (grid[r][c] != '.') {
        if (grid[r][c] == '/') {
            if (dir==1) {
                dir = 2;
            } else if (dir==2) {
                dir = 1;
            } else if (dir==3) {
                dir = 4;
            } else if (dir==4) {
                dir = 3;
            }
        } else if (grid[r][c] == '\\') {
            if (dir==1) {
                dir = 4;
            } else if (dir==2) {
                dir = 3;
            } else if (dir==3) {
                dir = 2;
            } else if (dir==4) {
                dir = 1;
            }
        }
    } 

    if (dir == 1) {
        return laser(grid, visited, r-1, c, 1);
    } else if (dir == 2) {
        return laser(grid, visited, r, c+1, 2);
    } else if (dir == 3) {
        return laser(grid, visited, r+1, c, 3);
    } else if (dir == 4) {
        return laser(grid, visited, r, c-1, 4);
    }
}

vector<vector<bool>> visitedMirror;

string simulate(vector<string>& grid, int pos, int dir) {
    // cout << "pos: " << pos << " dir: " << dir << endl;
    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid[0].size();j++) {
            if (grid[i][j] == '.') {
                visitedMirror[i][j] = true;
            } else {
                visitedMirror[i][j] = false;
            }
        }
    }

    string exit = "";
    if (dir == 1) {
        exit = laser(grid, visitedMirror, grid.size()-1, pos, 1);
    } else if (dir == 2) {
        exit = laser(grid, visitedMirror, pos, 0, 2);
    } else if (dir == 3) {
        exit = laser(grid, visitedMirror, 0, pos, 3);
    } else {
        exit = laser(grid, visitedMirror, pos, grid[0].size()-1, 4);
    }

    bool isGood = true;
    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid[0].size();j++) {
            if (visitedMirror[i][j] == false) {
                isGood = false;
                break;
            }
        }
        if (!isGood) {
            break;
        }
    }

    string ans = "";
    if (isGood) {
        if (dir == 1) {
            ans += ("S" + to_string(pos+1) + " ");
        } else if (dir == 3) {
            ans += ("N" + to_string(pos+1) + " ");
        } else if (dir == 2) {
            ans += ("W" + to_string(pos+1) + " ");
        } else {
            ans += ("E" + to_string(pos+1) + " ");
        }

        string trimmedExit = "";
        for (char a : exit) {
            if (a!=' ') {
                trimmedExit.push_back(a);
            }
        }
        ans += trimmedExit;
    }

    return ans;

}

void solve() {
    int r, c; cin >> r >> c;
    vector<string> grid(r);
    for (int i=0;i<r;i++) {
        cin >> grid[i];
    }

    for (int i=0;i<r;i++) {
        vector<bool> rowOfGraph;
        for (int j=0;j<c;j++) {
            if (grid[i][j] != '.') {
                rowOfGraph.push_back(false);
            } else {
                rowOfGraph.push_back(true);
            }
        }
        visitedMirror.push_back(rowOfGraph);
    }

    set<string> ans;
    string possible = "";
    for (int i=0;i<r;i++) {
        possible = simulate(grid, i, 2);
        if (possible.size() != 0) {
            auto pos = possible.find(' ');
            ans.insert(possible.substr(0, pos));
            ans.insert(possible.substr(pos+1));
        }
        possible = simulate(grid, i, 4);
        if (possible.size() != 0) {
            auto pos = possible.find(' ');
            ans.insert(possible.substr(0, pos));
            ans.insert(possible.substr(pos+1));
        }
    }

    for (int i=0;i<c;i++) {
        possible = simulate(grid, i, 3);
        if (possible.size() != 0) {
            auto pos = possible.find(' ');
            ans.insert(possible.substr(0, pos));
            ans.insert(possible.substr(pos+1));
        }
        possible = simulate(grid, i, 1);
        if (possible.size() != 0) {
            auto pos = possible.find(' ');
            ans.insert(possible.substr(0, pos));
            ans.insert(possible.substr(pos+1));
        }
    }

    cout << ans.size() << '\n';
    if (ans.size()) {
        for (auto& a : ans) {
            cout << a << " ";
        }
        cout << '\n';
    }
}

int main() {
    // int t; cin >> t;
    // while (t--) {
        solve();
    // }
}