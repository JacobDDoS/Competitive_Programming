#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, s; cin >> n >> s;
    int low; cin >> low;
    int high = low;
    for (int i=0;i<n-1;i++) {
        cin >> high;
    }
    
    if (s >= high) {
        cout << s - low << endl;
    } else if (s <= low) {
        cout << high - s << endl;
    } else {
        cout << min(s-low + high-low, high-s + high-low) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}