#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
  int n, k; cin >> n >> k;
  if (k==n*n-1) {cout << "NO\n"; return;}
  vector<vector<char>> v;
  while (k >= n) {
    vector<char> g(n, 'R');
    v.push_back(g);
    k-=n;
  }
  vector<char> g(n, 'R');
  if (k != n-1) {
    g[n-k-1] = 'L';
    v.push_back(g);
  } else {
    g[0] = 'D';
    v.push_back(g);
  }

  while (v.size() < n) {
    vector<char> g(n, 'R');
    g[n-1] = 'L';
    v.push_back(g);
  }
  
  cout << "YES\n";
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
        cout << v[i][j];
    }
    cout << '\n';
  }


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