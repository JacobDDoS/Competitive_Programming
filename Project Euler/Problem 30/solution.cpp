#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int sumOfFifthPowers(int i) {
    string str = to_string(i);
    int sum = 0;
    for (char c : str) sum += pow((c-'0'), 5);
    return sum;
}

int main()
{
    int ans = 0;
    for (int i=10;i<354294;i++) { // 354294 is 9^5. Consider that adding any more nines will cause it to grow faster as a number than the sum will. Therefore this is a ceiling.
        if (i == sumOfFifthPowers(i)) {
            cout << "Found a number that can be written as the sum of its digits to the fifth power: " << i << endl;
            ans += i;
        }
    }
    cout << "The total sum is " << ans << endl;
}