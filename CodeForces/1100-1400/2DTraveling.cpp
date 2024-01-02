#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

int dist(vector<int> pt1, vector<int> pt2) {
    return (abs(pt1[0]-pt2[0]) + abs(pt1[1]-pt2[1]));
}

void solve() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<vector<int>> cities;
    for (int i=0;i<n;i++) {
        vector<int> city(2);
        cin >> city[0] >> city[1];
        cities.push_back(city);
    }

    int ans = dist(cities[a-1], cities[b-1]);

    int tS = 999999999, fS = 999999999;
    for (int i=0;i<k;i++) {
        tS = min(tS, dist(cities[a-1], cities[i]));
        fS = min(fS, dist(cities[b-1], cities[i]));
    }

    ans = min(ans, tS+fS);
    cout << ans << endl;

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