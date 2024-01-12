#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i=0;i<n;i++) {
        if ((s[i]=='.' && (i==0 || i==n-1)) || (s[i] == '.' && s[i+1]=='#')  || (s[i] == '.' && s[i-1] == '#') ) {
            ans++;
        } else if (s[i]=='.') {
            ans = 2;
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}