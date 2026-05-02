#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    freopen("numbers.txt", "r", stdin);
    cpp_int sum = 0;
    string str;
    while (cin >> str) {
        cpp_int a(str);
        sum += a;
    }
    string ans = sum.str();
    cout << "The first ten digits are " << ans.substr(0, 10) << endl;
}