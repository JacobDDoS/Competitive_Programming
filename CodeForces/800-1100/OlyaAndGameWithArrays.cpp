#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
/*
1
2
2
1 2
2
4 3
*/
 
void solve() {
	int n; cin >> n;
  vector<vector<int>> ars;
  vector<int> numsToAdd;
  int indxOfArrWithSmallestValue=0;
  for (int i=0;i<n;i++) {
    int m; cin >> m;
    vector<int> ar(m);
    for (int j=0;j<m;j++) {
      cin >> ar[j];
    }
    sort(ar.begin(), ar.end());
    if (ars.size()>0&&ar[0] < ars[indxOfArrWithSmallestValue][0]) {
      indxOfArrWithSmallestValue = ars.size();
    }
    ars.push_back(ar);
  }
 
  if (n == 1) {
    cout << ars[0][0] << '\n';
    return;
  }
 
  ll ans = 0;
  for (int i=0;i<n;i++) {
    if (i==indxOfArrWithSmallestValue) {
      // numsToAdd.push_back(ars[i][0]);
      continue;
    } else {
      numsToAdd.push_back(ars[i][1]);
    }
  }
  sort(numsToAdd.begin(), numsToAdd.end());
  numsToAdd[0] = max(numsToAdd[0], ars[indxOfArrWithSmallestValue][1]);
  numsToAdd.push_back(ars[indxOfArrWithSmallestValue][0]);
  for (int i=0;i<n;i++) {
    ans += numsToAdd[i];
  }
  cout << ans << '\n';
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