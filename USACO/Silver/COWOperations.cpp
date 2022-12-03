#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    string s; cin >> s;
    vector<int> C(s.size(), 0);
    vector<int> O(s.size(), 0);
    vector<int> W(s.size(), 0);

    for (int i=0;i<s.size();i++) {
        if (i != 0) {
            C[i] = C[i-1];
            O[i] = O[i-1];
            W[i] = W[i-1];
        }
        if (s[i] == 'C') {
            C[i]++;
        } else if (s[i] == 'O') {
            O[i]++;
        } else if (s[i] == 'W') {
            W[i]++;
        }
    }

    string ans = "";

    int Q; cin >> Q;
    for (int i=0;i<Q;i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        int Ccount = C[r];
        int OCount = O[r];
        int WCount = W[r];
        if (l != 0) {
            Ccount -= C[l-1];
            OCount -= O[l-1];
            WCount -= W[l-1];
        }

        int dif = abs(OCount - WCount);
        if ((Ccount + min(OCount, WCount))&1 && !(dif&1)) {
            ans += 'Y';
        } else {
            ans += 'N';
        }
    }

    cout << ans << '\n';

}


int main() {
    solve();
}