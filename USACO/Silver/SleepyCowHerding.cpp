#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n; cin >> n;
    vector<int> cows(n);
    for (int i=0;i<n;i++) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    //To find the min, look for blocks of n spaces, such that there is the maximum number of cows, then subtract n by how many cows there already are
    //Also check if there is enough space for the case there is a continuous block of cows, but one outlier, if this is the case then make sure that ptr is subtracted by 1
        //This is because that one outlier needs a place to go, but it cannot be an outlier again so one inside number as to move out a little bit so that it can move in
        //And that requires 2 moves, not one (so to fix this, subtract ptr by 1 as it's later used in the calculation n - ptr)
    //To do this in O(nlogn) use lower bound
    int maxNumberOfCowsWithinN = 0;
    for (int i=0;i<n-1;i++) {
        int currentCowPosition = cows[i];
        int maxCowPosition = currentCowPosition+n;
        int ptr = lower_bound(cows.begin(), cows.end(), maxCowPosition) - cows.begin() - i;
        int maxMinusMin = cows[cows[ptr+i] < maxCowPosition ? ptr : ptr-1] - cows[i] + 1;

        //this occurs when there is a continous block of cows 
        //note that it checks for only one outlier
        if (ptr == maxMinusMin && ptr == n - 1) {
            ptr--;
        }

        maxNumberOfCowsWithinN = max(maxNumberOfCowsWithinN, ptr);
    }

    //To find the max, count the number of spaces starting from the second number, both increasing and decreasing order
    ll maxInc = 0;
    ll maxDec = 0;
    for (int i=2;i<n;i++) {
        maxInc += cows[i] - cows[i-1] - 1; 
    }

    for (int i=n-2;i>=1;i--) {
        maxDec += cows[i] - cows[i-1] - 1; 
    }

    cout << n - maxNumberOfCowsWithinN << endl;
    cout << max(maxInc, maxDec) << endl;
}