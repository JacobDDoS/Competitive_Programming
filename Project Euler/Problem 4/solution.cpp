#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool isPalindrome(int n) {
    string str = to_string(n);
    for (int i=0;i<str.size();i++) {
        if (str[i] != str[str.size()-1-i]) return false;
    }
    return true;
}

void solve()
{
    int largest = 0;
    for (int a=100;a<=999;a++) {
        for (int b=100;b<=999;b++) {
            if (isPalindrome(a*b)) largest = max(largest, a*b);
        }
    }
    cout << "The largest palindrome made by the product of two 3 digit numbers is " << largest << endl;
}

int main()
{
    solve();
}