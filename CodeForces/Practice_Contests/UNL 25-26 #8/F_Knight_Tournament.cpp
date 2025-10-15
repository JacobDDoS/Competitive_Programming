#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    set<int> s;
    for (int i=1;i<=n;i++) { // O(nlogn)
        s.insert(i);
    }
    vector<vector<int>> fights(m, vector<int>(3,0));
    for (int i=0;i<m;i++) { // O(m)
        cin >> fights[i][0] >> fights[i][1] >> fights[i][2];
    }

    vector<int> v(n, 0), temp(n, -1);
    for (int i=0;i<m;i++) { // O(m)
        int l = fights[i][0], r = fights[i][1], winner = fights[i][2], ptr=0;
        auto itr = lower_bound(s.begin(), s.end(), l); // O(logn)
        while (itr != s.end() && (*itr)<=r) { // O(n)
            if ((*itr) != winner) { 
                v[(*itr)-1] = winner;
                temp[ptr++] = ((*itr));
            }
            itr++;
        }

        for (int i=0;i<n;i++) { // O(nlogn)
            int elm = temp[i];
            if (elm == -1) break;
            s.erase(elm);
            temp[i] = -1;
        }
    }

    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}