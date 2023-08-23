#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/*
1
3
4
1 2 4 8
3
2 9 1
2
1 4
*/

void solve() {
	int m; cin >> m;
  vector<vector<int>> days;
  for (int i=0;i<m;i++) {
    int t; cin >> t;
    vector<int> numsOfPart(t);
    for (int i=0;i<t;i++) {
      cin >> numsOfPart[i];
    }
    days.push_back(numsOfPart);
  }

  map<int, int> mp;
  for (int i=m-1;i>=0;i--) {
    vector<int> day = days[i];
    for (int num : day) {
      if (mp[num]==0) {
        mp[num]=i;
      }
    }
  }

  vector<int> sol(m, -1);
  for (auto pr : mp) {
    sol[pr.second] = pr.first; 
  }

  for (int i=0;i<m;i++) {
    if (sol[i] == -1) {
      cout << "-1\n";
      return;
    }
  }

  for (int i=0;i<m;i++) {
    cout << sol[i] << " ";
  }
  cout << endl;
  
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