#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

vector<int> fact(10, 1);

bool isValid(int n) {
    int sum = 0;
    for (char c : to_string(n)) sum += fact[c-'0'];
    return sum == n;
}

int main()
{
    for (int i=2;i<10;i++) {
        for (int j=1;j<=i;j++) {
            fact[i] *= j;
        }
    }
    int ans = 0;

    // Anything beyond 9! * 6 = 2,177,280 isn't reachable since you'd have to turn all digits to 9's to get close
    for (int i=10;i<2'177'280;i++) {
        if (isValid(i)) {
            ans += i;
        }
    }

    cout << "The sum of all numbers equal to the sum of the factorial of their digits is " << ans << endl;

}