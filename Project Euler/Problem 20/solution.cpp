#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    cpp_int a = 1;
    for (int i=2;i<=100;i++) {
        a *= i;
    }
    string s = a.str();
    int ans = 0;
    for (char c : s) ans += (c-'0');
    cout << "The sum of the digits of 100! is " << ans << endl;
}