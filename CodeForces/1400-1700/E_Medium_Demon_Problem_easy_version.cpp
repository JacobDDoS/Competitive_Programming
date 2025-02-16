#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> spiders(n);
    vector<int> to(n, 0);
    for (int i=0;i<n;i++) {
        cin >> spiders[i];
        to[spiders[i]-1]++;
    }

    queue<int> q;
    for (int i=0;i<n;i++) {
        if (to[i] == 0) {
            q.push(i);
        }
    }

//     for (auto i : to) {
//         cout << i << " ";
//     }
// cout << endl;
    int ans = 2;
    int sizeOfPQ = q.size();
    while (q.size()) {
        // cout << "size of pq: " << sizeOfPQ << endl;
        if (--sizeOfPQ == 0) {
            ans++;
        }

        int dead = q.front(); q.pop();
        // cout << "dead: " << dead << endl;
        to[(spiders[dead]-1)] -= 1;
        if (to[(spiders[dead]-1)] == 0) {
            q.push((spiders[dead]-1));
        }

        if (sizeOfPQ == 0) {
            sizeOfPQ = q.size();
        }
    }

    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}