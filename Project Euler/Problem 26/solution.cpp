#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int cycleLength(int n) {
    map<int, int> mp;
    mp[1] = 1;
    int cur = 1, cnt = 1;
    while (true) {
        cnt++;
        cur *= 10;
        cur %= n;
        if (cur == 0) return 0;
        if (mp[cur]) return (cnt-mp[cur]);
        mp[cur] = cnt;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int maxCycle = 1, ans = 1;
    for (int i=2;i<1000;i++) {
        int len = cycleLength(i);
        if (len > maxCycle) {
            maxCycle = len;
            ans = i;
        }
    }
    cout << "The number with the max cycle length is " << ans << " with a cycle length of " << maxCycle << endl;
}