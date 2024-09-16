#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pieces(k);
    for (int i=0;i<k;i++) {
        cin >> pieces[i];
    }

    int maxi = pieces[0];
    for (int i=1;i<pieces.size();i++) {
        maxi = max(maxi, pieces[i]);
    }

    int ans = 0;
    for (int i=0;i<pieces.size();i++) {
        ans += pieces[i] + (pieces[i]-1);
    }
    ans -= (maxi + (maxi-1));
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}