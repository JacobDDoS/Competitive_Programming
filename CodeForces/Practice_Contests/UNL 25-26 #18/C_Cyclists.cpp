#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k, p, m; cin >> n >> k >> p >> m;
    vector<int> cost(n+1, 0);
    for (int i=1;i<=n;i++) cin >> cost[i];
    int ans = 0;
    if (n == k) {
        cout << m/cost[p] << '\n';
        return;
    } else if (cost[p] > m) {
        cout << "0\n";
        return;
    } 


    if (p <= k) {
        ans++;
        m -= cost[p];
    } else {
        sort(cost.begin(), cost.begin() + p);
        for (int i=1;i<=p-1-(k-1);i++) {
            // cout << "cost[" << i << "]: " << cost[i] << endl;
            m -= cost[i];
        }

        // cout << "m: " << m << ", cost[p]: " << cost[p] << endl;
        if (m >= cost[p]) {
            m -= cost[p];
            ans++;
        } else {
            cout << "0\n";
            return;
        }
    }


    int pCost = cost[p], sum = pCost;
    cost.erase(cost.begin()+p);
    sort(cost.begin(), cost.end());
    for (int i=1;i<=n-1-(k-1);i++) {
        // cout << "adding to sum: " << cost[i] << endl;
        sum += cost[i];
    }
    // cout << "sum: " << sum << endl;

    ans += (m/sum);
    cout << ans << '\n';

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