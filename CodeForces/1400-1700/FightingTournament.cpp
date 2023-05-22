// Author: JacobDDoS 
// Date: 5/22/23
// Problem: Fighting Tournament

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, q; cin >> n >> q;
    vector<pair<int, int>> s(n);
    for (int i=1;i<=n;i++) {
        int a;
        cin >> a;
        s[i-1] = make_pair(i, a);
    }

    int round = 0;
    int ptr1=0, ptr2=1;
    map<int, int> idToS;
    for (auto& pr : s) {
        idToS[pr.first] = pr.second;
    }

    map<int, vector<int>> vic;
    while (s[ptr1].second != n && s[ptr2].second != n) {
        round++;
        if (s[ptr1].second > s[ptr2].second) {
            ptr2 = max(ptr1, ptr2) + 1;
            vic[s[ptr1].first].push_back(ptr2);
        } else {
            ptr1 = max(ptr1, ptr2) + 1;
            vic[s[ptr2].first].push_back(ptr1);
        }
    }

    for (int i=0;i<q;i++) {
        int id, k; cin >> id >> k;
        if (idToS[id] == n && k >= round) {
            int wins = vic[id].size() + (k-round);
            cout << wins << '\n';
        } else if (k >= round) {
            cout << vic[id].size() << '\n';
        } else {
            int upToK = lower_bound(vic[id].begin(), vic[id].end(), k+2) - vic[id].begin();
            cout << upToK << '\n';
        }
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