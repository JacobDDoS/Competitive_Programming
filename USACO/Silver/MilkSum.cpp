#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    // freopen("3.in", "r", stdin);
    // freopen("our3.out", "w", stdout);
    int n; cin >> n;
    vector<pair<ll,ll>> cMA(n); //cow milk amounts
    unordered_map<ll, ll> idxM; // Index map
    for (ll i=0;i<n;i++) {
        cin >> cMA[i].first;
        cMA[i].second = i;
    }

    sort(cMA.begin(), cMA.end());

    for (int i=0;i<n;i++) {
        idxM[cMA[i].second] = i;
    }

    vector<ll> pfS(n+1); //prefix sum
    pfS[0] = 0;
    for (ll i=0;i<n;i++) {
        pfS[i+1] = pfS[i] + cMA[i].first;
    }

    ll bM = 0; //base max
    for (ll i=0;i<n;i++) {
        bM += cMA[i].first*(i+1);
    }


    ll q; cin >> q;
    for (ll i=0;i<q;i++) {
        ll idx, newV; cin >> idx >> newV;
        idx-=1;
        ll idxInOrder = idxM[idx];
        ll newIdx = upper_bound(cMA.begin(), cMA.end(), make_pair(newV, (ll)-1)) - cMA.begin();
        ll bMD = 0; // base max difference
        bMD += (newV*(newIdx+(newIdx > idxInOrder ? 0 : 1))-cMA[idxInOrder].first*(idxInOrder+1));
        // cout << "bMD: " << bMD << " " << cMA[idxInOrder].first << endl;
        bMD -= (pfS[newIdx] - pfS[idxInOrder+(newIdx <= idxInOrder ? 0 : 1)]);
        // cout << "Pfs: " << pfS[newIdx] << " " << pfS[idxInOrder+1] << endl;

        // cout << "Data: " << idxInOrder << " " << newIdx << " " << bMD << " " << bM << endl;
        cout << bM + bMD << '\n';
    } 

}