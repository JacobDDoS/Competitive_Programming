#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=n;i>m;i--) {
        cout << i << " ";
    }
    for (int i=1;i<=m;i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}