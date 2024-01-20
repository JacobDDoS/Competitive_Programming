#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int n; cin >> n;
    vector<ll> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    if (n == 1) {
        cout << "1\n";
        return;
    }

    sort(nums.begin(), nums.end());

    ull gcdOfAllDifferences = nums[nums.size()-1] - nums[0];
    for (int i=0;i<n;i++) {
        gcdOfAllDifferences = gcd(gcdOfAllDifferences, nums[nums.size()-1] - nums[i]);
    }


    ull newElm;
    for (int i=n-1;;i--) {
        if (i == 0) {
            newElm = nums[0]-gcdOfAllDifferences;
            break;
        }
        if (nums[i]-gcdOfAllDifferences != nums[i-1]) {
            newElm = nums[i]-gcdOfAllDifferences;
            break;
        }
    }

    ull ans = (nums[nums.size()-1] - newElm)/gcdOfAllDifferences;
    for (int i=0;i<n;i++) {
        ans += (nums[nums.size()-1] - nums[i])/gcdOfAllDifferences;
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