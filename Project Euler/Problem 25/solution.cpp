#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    // freopen("input.txt", "r", stdin);
    cpp_int a = 1, b = 1, temp;
    int idx = 1;
    while (true) {
        if (a.str().size() == 1000) {
            cout << "The index of the first term with 1000 digits is " << idx << endl;
            break;
        }
        temp = a, a = b, b += temp;
        idx++;
    }
}