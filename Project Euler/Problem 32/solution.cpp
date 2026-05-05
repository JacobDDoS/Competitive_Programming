#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

bool isValid(string a, string b, string c) {
    return (stoi(a)*stoi(b)==stoi(c));
}

int main()
{
    // the below algorithm is O(n! * n^3), but it will do for n==9
    string str = "123456789";
    set<int> s;
    int ans = 0;
    do {
        for (int i=0;i<str.size()-2;i++) {
            for (int j=i+1;j<str.size()-1;j++) {
                if (isValid(str.substr(0, i+1), str.substr(i+1, j-i), str.substr(j+1, str.size()-j))) {
                    cout << str.substr(0, i+1) << " x " << str.substr(i+1, j-i) << " = " << str.substr(j+1, str.size()-j) << endl;
                    s.insert(stoi(str.substr(j+1, str.size()-j)));
                }
            }
        }
    } while (next_permutation(str.begin(), str.end()));
    for (int i : s) {
        cout << "possible product: " << i << endl;
        ans += i;
    }
    cout << "The sum of all products which can be written as a 1 through 9 pandigital is " << ans << endl;
}