#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    k--;
    long long ratings[n];
    for (int i=0;i<n;i++) {
        cin >> ratings[i];
    }

    int ans1 = 0, ans2 = 0;

    swap(ratings[0], ratings[k]);
    for (int i=1;i<n;i++) {
        if (ratings[i] < ratings[0]) {
            ans1++;
        } else {
            break;
        }
    }

    swap(ratings[0], ratings[k]);

    int bigIdx = -1;
    for (int i=0;i<k;i++) {
        if (ratings[i] > ratings[k]) {
            bigIdx = i;
            break;
        }
    }

    swap(ratings[bigIdx], ratings[k]);

    if (bigIdx != -1) {
        if (bigIdx != 0) {
            ans2++;
        }

        for (int i=bigIdx+1;i<n;i++) {
            if (ratings[i] < ratings[bigIdx]) {
                ans2++;
            } else {
                break;
            }
        }
    }



    cout << max(ans1, ans2) << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}