#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string> 

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool bfs(int curPos, int n, int m, int swimLeft, string& river, vector<int>& maxSwim) {

    if (curPos > 0 && river[curPos-1] == 'W') {
        for (int i=1;i<=swimLeft;i++) {
            if (curPos+i == n+1 || (curPos+i < n+1 && river[curPos+i-1] != 'C')) {
                maxSwim[curPos+i] = max(maxSwim[curPos+i], swimLeft-i);
            } else {
                break;
            }
        }
    } else if (curPos==0 || river[curPos-1] == 'L') {
        for (int i=1;i<=m;i++) {
            if (curPos+i == n+1 || (curPos+i < n+1 && river[curPos+i-1] != 'C')) {
                maxSwim[curPos+i] = max(maxSwim[curPos], maxSwim[curPos+i]);
            }
        }
    }

    return false;
}

void solve() {
    int n, m, k;
    string str;
    cin >> n >> m >> k >> str;

    vector<int> maxSwim(n+2);
    for (int i=0;i<n+2;i++) {
        maxSwim[i] = -1;
    }
    maxSwim[0] = k;

    for (int i=0;i<=n;i++) {
        if (maxSwim[i] != -1) {
            bfs(i, n, m, maxSwim[i], str, maxSwim);
        }
    }
    

    if (maxSwim[n+1] != -1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}