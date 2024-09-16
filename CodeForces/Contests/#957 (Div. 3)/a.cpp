#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve() {
    int a, b, c; 
    cin >> a >> b >> c;
    for (int i=0;i<5;i++) {
        if (a <= b && a <= c) {
            a++;
        } else if (b <=a && b <= c) {
            b++;
        } else {
            c++;
        }
    }
    cout << (a*b*c) << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}