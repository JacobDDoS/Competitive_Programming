// Author: JacobDDoS 
// Date: 8/21/23
// Problem: B. Berland Music

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> rt(n);
    for (int i=0;i<n;i++) {
        cin >> rt[i];
    }
    string s; cin >> s;
    int l = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='0'){
            l++;
        }
    }
    vector<int> nr(n, -1);

    set<int> low, high;
    for (int i=1;i<=l;i++) {
        low.insert(i);
    }

    for (int i=l+1;i<=n;i++) {
        high.insert(i);
    }

    for (int i=0;i<n;i++) {
        if (rt[i]<=l && s[i]=='0') {
            nr[i] = rt[i];
            low.erase(rt[i]);
        } else if (rt[i]>l&&s[i]=='1') {
            nr[i] = rt[i];
            high.erase(rt[i]);
        }
    }


    for (int i=0;i<n;i++) {
        if (nr[i] == -1) {
            int newN = 2;
            if (s[i]=='0') {
                newN = *(low.begin());
                low.erase(newN);
                nr[i] = newN;
            } else {
                newN = *(high.begin());
                high.erase(newN);
                nr[i] = newN;
            }
        }
    }


    for (int i=0;i<n;i++) {
        cout << nr[i] << " ";
    }

    cout << '\n';
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}