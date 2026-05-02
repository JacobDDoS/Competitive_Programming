#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};
    int curDay = 0, ans = 0;
    for (int year=1900;year<=2000;year++) {
        for (int month=0;month<12;month++) {
            if (curDay == 6 && year!=1900) ans++;
            if (month == 1) {
                curDay += (days[month] + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0) % 7;
                curDay %= 7;
            } else {
                curDay += days[month] % 7;
                curDay %= 7;
            }
        }
    }
    cout << "The number of Sundays from January 1st 1901 to December 31 2000 is " << ans << endl;
}