#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, selected; cin >> n >> selected;
    ll multiplier = 1;
    ll totalOddCards = (n)/(ll)2 + (n%2);
    ll currentCards = totalOddCards;

    int cnt = 0;
    while (selected - currentCards > 0 && currentCards != 0) {
        selected -= currentCards;
        multiplier *= 2;
        currentCards = (n/multiplier)/2 + ((n/multiplier)%2);
        cnt++;
    }

    ll card = (1+2*(selected-1))*multiplier;
    cout << card << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}