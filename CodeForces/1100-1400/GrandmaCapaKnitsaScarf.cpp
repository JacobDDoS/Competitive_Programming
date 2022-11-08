// Author: JacobDDoS 
// Date: 11/7/22
// Problem: Grandma Capa Knits a Scarf

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int ans = 999999;
    for (int i=0;i<alphabet.size();i++) {
    int leftPtr = 0;
    int rightPtr = s.size()-1;
    char letter = alphabet[i];
    int maybeAns = 0;
    bool good = true;
        while (leftPtr < rightPtr) {
            if (s[leftPtr] == s[rightPtr]) {
                leftPtr++;
                rightPtr--;
            } else if (s[leftPtr] == letter) {
                maybeAns++;
                leftPtr++;
            } else if (s[rightPtr] == letter) {
                rightPtr--;
                maybeAns++;
            } else {
                good = false;
                break;
            }
        }
        if (good) {
            ans = min(ans, maybeAns);
        }
    }

    if (ans == 999999) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}