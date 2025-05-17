#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define MOD 1'000'000'007

ld exponentiate(ld x, ll p, unordered_map<ll, ld>& expMp) {
    ld result = 0;
    if (expMp[p] != 0) return expMp[p];
    if (!(p&1)) {
        result = exponentiate(x, p/2, expMp) * exponentiate(x, p/2, expMp);
    }
    else {
        result = x * exponentiate(x, p-1, expMp);
    }
    expMp[p] = result;
    return result;
}

ld power(ld x, ll p) {
    unordered_map<ll, ld> mp;
    mp.reserve(150);
    mp[0] = 1.0;
    mp[1] = x;
    return exponentiate(x, p, mp);
}

int main() {
    int m, n; cin >> m >> n;
    vector<ld> p(m+1);
    p[0] = 0;
    ld curProb = 0;
    ld ans = 0;
    for (int i=1;i<=m;i++) {
        p[i] = power((ld)i/m, n) - curProb;
        curProb += p[i];
        ans += p[i]*i;
    }
    
    cout << fixed << setprecision(12) << ans << endl;

}