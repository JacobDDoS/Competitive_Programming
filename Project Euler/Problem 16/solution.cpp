#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    cpp_int num = pow(cpp_int(2), 1000);
    string str = num.str();
    int ans = 0;
    for (char c : str) ans += c-'0';
    cout << "The sum of the digits of 2^1000 is " << ans << endl;
}