#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k; cin >> n >> k;
    long long curSub = (n-1)*2;

    vector<int> perm(n);
    for (int i=1;i<=n;i++) {
        perm[i-1] = i;
    }

    int ptr = n-1;
    bool hasUnswapped = false;
    int unSwappedPos = -1;
    while (curSub >= 2) {
        if (k - curSub >= 0) {
            k -= curSub;
            swap(perm[ptr], perm[(n-1)-ptr]);
        } else if (!hasUnswapped) {
            hasUnswapped = true;
            unSwappedPos = ptr;
        }
        ptr--;
        curSub -= 4;
    }

    if (k == 0 || (k==2 && (hasUnswapped) )) {
        if (hasUnswapped && k==2) {
            swap(perm[unSwappedPos], perm[unSwappedPos-1]);
        }
        cout << "YES\n";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}