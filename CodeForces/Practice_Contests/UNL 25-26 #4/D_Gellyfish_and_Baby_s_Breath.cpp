#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;
unordered_map<int, long long> mp;


long long powerOfTwo(long long x) {
    if (mp[x] != 0) {
        return mp[x];
    }
    if (x&1) {
        mp[x] = (((2 * powerOfTwo(x/2)) % MOD) * powerOfTwo(x/2)) % MOD;
    } else {
        mp[x] = (powerOfTwo(x/2) * powerOfTwo(x/2)) % MOD;
    }
    return mp[x];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n), r(n);
    for (int i=0;i<n;i++) {
        cin >> p[i];
    }
    for (int i=0;i<n;i++) {
        cin >> q[i];
    }
    int maxP = 0, maxQ = 0;
    for (int i=0;i<n;i++) {
        if (p[i] > p[maxP]) {
            maxP = i;
        }
        if (q[i] > q[maxQ]) {
            maxQ = i;
        }
        if (p[maxP] > q[maxQ] || (p[maxP] == q[maxQ] && q[i-maxP] >= p[i-maxQ])) {
            r[i] = (powerOfTwo(p[maxP]) + powerOfTwo(q[i-maxP])) % MOD;
        } else {
            r[i] = (powerOfTwo(q[maxQ]) + powerOfTwo(p[i-maxQ])) % MOD;
        }
    }

    for (int a : r) {
        cout << a << " ";
    }
    cout << "\n";

}

int main()
{
    mp[0]=1;
    mp[1]=2;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}