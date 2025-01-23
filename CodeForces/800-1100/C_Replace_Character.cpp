#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    int maxOcc = 1, minOcc = 101;
    map<char, int> mp;
    for (int i=0;i<str.size();i++) {
        mp[str[i]]++;
        maxOcc = max(maxOcc, mp[str[i]]);
    }

    for (auto& pr : mp) {
        minOcc = min(minOcc, pr.second);
    }

    char chosenChar;
    for (auto& pr : mp) {
        if (pr.second == maxOcc) {
            chosenChar = pr.first;
            break;
        }
    }

    for (int i=0;i<n;i++) {
        if (str[i] != chosenChar && mp[str[i]] == minOcc) {
            str[i] = chosenChar;
            break;
        }
    }
    cout << str << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}