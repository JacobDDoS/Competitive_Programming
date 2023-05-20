// Author: JacobDDoS 
// Date: 5/19/23
// Problem: Doremy's IQ

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

string startSolve(int n, int q, int st, string str, vector<int>& dif) {
        for (int j=st;j<n;j++) {
            if (dif[j] > q) {
                q--;
            }
            str[j] = '1';
        }
        if (q < 0) {
            return "n";
        } 
        return str;
}

void solve(int n, int q, int test) {
    vector<int> dif(n);
    string str = "";
    for (int i=0;i<n;i++) {
        cin >> dif[i];
        if (dif[i] <= q) {
            str.append("1");
        } else {
            str.append("0");
        }
    }

    // if (test == 5511) {
    //     string outStr = std::to_string(n) + "+" + std::to_string(q) + "+";
    //     for (auto& num : dif) {
    //         outStr.append(std::to_string(num)+".");
    //     }
    //     cout << outStr;
    // }

    if (q >= n) {
        for (int i=0;i<n;i++) {
            str[i] = '1';
        }
        cout << str << '\n';
        return;
    }
    

    int first = 0, last = n;
    while (first < last) {
        int middle = (first+last)/2;
        if (startSolve(n, q, middle, str, dif) == "n") {
            first = middle+1;
        } else {
            last = middle;
        }
    }

    cout << startSolve(n, q, (first+last)/2, str, dif) << '\n';
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    int test = 1;
    while (test <= t) {
        test++;
        int n, q; cin >> n >> q;
        solve(n, q, test);
    }
    //solve();
}