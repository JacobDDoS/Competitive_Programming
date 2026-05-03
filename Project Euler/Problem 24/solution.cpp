#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    string str = "0123456789";
    int cur = 1;
    while (cur < 1'000'000) {
        next_permutation(str.begin(), str.end());
        cur++;
    }
    cout << "The millionth lexicographic permutation is " << str << endl;
}