#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
void solve() {
	int n, m; cin >> n >> m;
  vector<int> d1(n+m-1);
  vector<int> d2(n+m-1);
  vector<vector<int>> v;
  for (int i=0;i<n;i++) {
    vector<int> row;
    for (int j=0;j<m;j++) {
      int num; cin >> num;
      row.push_back(num);
      int indexForD1 = (n-i-1)+j;
      int indexForD2 = i+j;
      d1[indexForD1] += num;
      d2[indexForD2] += num;
    }
    v.push_back(row);
  }
 
  int best = -1;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      int indexForD1 = (n-i-1)+j;
      int indexForD2 = i+j;
      best = max(best, d1[indexForD1] + d2[indexForD2]-v[i][j]);
    }
  }
  cout << best << '\n';
}
 
int main() {
	// For getting input from input.txt file
	// freopen("breedflip.in", "r", stdin);
 
	// // Printing the Output to output.txt file
	// freopen("breedflip.out", "w", stdout);
  int t; cin >> t;
  while (t--) {
	 solve();
  }
}