#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int n; cin >> n;
    vector<ll> deck(n);
    priority_queue<ll> st;
    ll ans = 0;
    for (int i=0;i<n;i++) {
        cin >> deck[i];
        if (deck[i] != 0) {
            st.push(deck[i]);
        } else {
            if (!st.empty()) {
                // cout << "adding: " << st.top() << endl;
                ans += st.top();
                st.pop();
            }
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