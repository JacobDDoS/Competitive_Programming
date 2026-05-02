#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

map<int, string> mp;

int letterCount(int n, bool verbose = false) {
    int ans = 0;

    // thousand
    if (n == 1000) {
        if (verbose) cout << "one thousand" << endl;
        return mp[1].length() + mp[1000].length();
    }

    // hundred
    if (n >= 100) {
        ans += mp[n/100].length() + mp[100].length();
        if (verbose) cout << mp[n/100] << " " << mp[100];
    }
    if (n >= 100 && n % 100 != 0) {
        ans += 3; // 'and'
        if (verbose) cout << " and";
    }
    // 1_
    if ((n%100)/10 == 1) {
        if (verbose) cout << " " << mp[(n%100)] << endl; 
        return ans + mp[(n%100)].length();
    }

    // tens 
    if ((n%100)/10 != 0) {
        ans += mp[(n%100)/10 * 10].length();
        if (verbose) cout << " " << mp[(n%100)/10 * 10];
    }

    // ones
    if (n%10 != 0) {
        ans += mp[n%10].length();
        if (verbose) cout << " " << mp[n%10];
    }
    if (verbose) cout << endl;
    return ans;
}

int main()
{
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
    mp[10] = "ten";
    mp[11] = "eleven";
    mp[12] = "twelve";
    mp[13] = "thirteen";
    mp[14] = "fourteen";
    mp[15] = "fifteen";
    mp[16] = "sixteen";
    mp[17] = "seventeen";
    mp[18] = "eighteen";
    mp[19] = "nineteen";
    mp[20] = "twenty";
    mp[30] = "thirty";
    mp[40] = "forty";
    mp[50] = "fifty";
    mp[60] = "sixty";
    mp[70] = "seventy";
    mp[80] = "eighty";
    mp[90] = "ninety";
    mp[100] = "hundred";
    mp[1000] = "thousand";

    int ans = 0;
    for (int i=1;i<=1000;i++) {
        int cnt = letterCount(i, true);
        cout << i << ": " << cnt << endl;
        ans += cnt;
    }

    cout << "The number of letters used to spell out 1 through 1000 is " << ans << endl;

}