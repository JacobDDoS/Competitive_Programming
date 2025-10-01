#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s; cin >> s;
    char winner;

    int bob = 0;
    for (char c : s) {
        if (c == 'B') bob++;
    }

    if (s[0] == s[n-1]) {
        if (s[0] == 'A') {
            winner = 'A';
        } else {
            winner = 'B';
        }
    } else if (s[0] == 'A' && s[n-1] == 'B') {
        if (bob > 1) {
            winner = 'B';
        } else {
            winner = 'A';
        }
    } else {
        if (s[n-2] == 'A') {
            winner = 'A';
        } else {
            winner = 'B';
        }
    }

    if (winner == 'A') {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}