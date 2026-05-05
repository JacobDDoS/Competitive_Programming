#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

bool floatsEqual(float a, float b) {
    if (abs(a-b) <= 1e-6) return true;
    return false;
}

bool isValid(int n, int d) {
    if (n/10 == d/10) {
        return floatsEqual((float)n/d, (float)(n%10)/(d%10));
    } else if (n % 10 == d / 10) {
        return floatsEqual((float)n/d, (float)(n/10)/(d%10));
    } else if (n/10 == d % 10) {
        return floatsEqual((float)n/d, (float)(n%10)/(d/10));
    } else if (n % 10 == d % 10) {
        return floatsEqual((float)n/d, (float)(n/10)/(d/10));
    }
    return false;
}

int main()
{
    vector<int> v;
    for (int i=11;i<99;i++) {
        if (!(to_string(i).contains('0'))) {
            v.push_back(i);
        }
    }

    int n = 1, d = 1;
    for (int i=0;i<v.size();i++) {
        for (int j=i+1;j<v.size();j++) {
            if (isValid(v[i], v[j])) {
                n *= v[i];
                d *= v[j];
            }
        }
    }

    d /= gcd(n, d);
    cout << "The denominator in its lowest common terms of the product of the four fractions is " << d << endl;


}