#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int properDivisorSum(int n) {
    int ans = 1;
    for (int i=2;i*i<=n;i++) {
        if (n % i == 0) {
            ans += i;
            if (i*i != n) ans += n/i;
        }
    }
    return ans;
}

int main()
{
    vector<bool> possible(28124, false);
    vector<int> abundantNums;
    for (int i=2;i<=28123;i++) {
        if (properDivisorSum(i) > i) {
            abundantNums.push_back(i);
        }
    }

    for (int a : abundantNums) {
        for (int b : abundantNums) {
            if (a+b >= possible.size()) break;
            possible[a+b] = true;
        }
    }

    int ans = 0;
    for (int i=0;i<possible.size();i++) {
        if (!possible[i]) {
            ans += i;
        }
    }
    cout << "The sum of positive integers which cannot be expressed as the sum of two abundant numbers is " << ans << endl;
}