#include <bits/stdc++.h>
using namespace std;

vector<bool> possi(100001, false);
vector<int> binaryDecimals = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000};

void solve() {
    int num; cin >> num;
    string numStr = to_string(num);
    for (int i=0;i<numStr.size();i++) {
        if (numStr[i] != '0' && numStr[i] != '1') {
            break;
        } else if (i == numStr.size()-1) {
            cout << "YES\n";
            return;
        }
    }

    if (possi[num]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    possi[1] = true;
    for (int i=1;i<=100000;i++) {
        if (possi[i]) {
            for (int num : binaryDecimals) {
                if (i*num <= 100000) {
                    possi[i*num] = true;
                }
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}