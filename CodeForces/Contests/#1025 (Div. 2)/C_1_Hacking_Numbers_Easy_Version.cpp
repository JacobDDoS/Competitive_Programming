#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    // n < 1,000,000,000
    // something -> 79 -> 16
    // two digits will make it <= 16
    // subtract 8 -> [1, 8] subtract 4 -> [1, 4] subtract 2 -> [1, 2] subtract 1 -> [1, 1] -> add n-1;

    cout << "digit\n";
    cout.flush();
    int x;
    cin >> x;
    cout << "digit\n";
    cout.flush();
    cin >> x;
    cout << "add -8\n";
    cout.flush();
    cin >> x;
    cout << "add -4\n";
    cout.flush();
    cin >> x;
    cout << "add -2\n";
    cout.flush();
    cin >> x;
    cout << "add -1\n";
    cout.flush();
    cin >> x;
    cout << "add " << (n - 1) << "\n";
    cout.flush();
    cin >> x;
    cout << "!\n";
    cout.flush();
    cin >> x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}