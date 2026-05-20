#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

bool isGood(int num) {
    string str = to_string(num);
    for (int i=0;i<str.size()/2;i++) {
        if (str[i] != str[str.size()-1-i]) return false;
    }
    int c = 0;
    for (int i=floor(log2(num));i>c;i--) {
        if ((bool)(num & (1<<i)) != (bool)(num & (1<<c))) return false;
        c++;
    }
    return true;
}

int main()
{
    ll ans = 0;
    for (int i=1;i<1'000'000;i++) {
        if (isGood(i)) {
            cout << "isGood: " << i << endl;
            ans += i;
        }
    }
    cout << "The sum of double-base palindromes below one million is " << ans << endl;
}