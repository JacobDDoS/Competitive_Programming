// Author: JacobDDoS 
// Date: 1/27/22
// Problem: Closest Cow Wins

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

ll getPointsFromPosition(ld position, ll& curMax, int leftCow, int rightCow, vector<int>& positions, vector<ll>& tastinessPS, vector<int>& rivalsCows) {
    auto leftEndpoint = lower_bound(positions.begin(), positions.end(), (rivalsCows[leftCow]+((position-(ld)rivalsCows[leftCow])/2))) - positions.begin();
    auto rightEndpoint = lower_bound(positions.begin(), positions.end(), (rivalsCows[rightCow]-(((ld)rivalsCows[rightCow]-position)/2))) - positions.begin()-1;
    cout << "arguments: " << position << " leftCow: " << rivalsCows[leftCow] << " rightCow: " << rivalsCows[rightCow] << endl;
    cout << "Results: " << (rivalsCows[leftCow]+((position-(ld)rivalsCows[leftCow])/2)) << " and " << (rivalsCows[rightCow]-(((ld)rivalsCows[rightCow]-position)/2)) << endl;

    cout << "left: " << leftEndpoint << " right: " << rightEndpoint << endl;    
    if (position - (position-(ld)leftCow)/2 - leftEndpoint < 1e-9) {
        leftEndpoint++;
    }

    // cout << "Result of equation: " << position + ((ld)rivalsCows[rightCow]-position)/2 - positions[rightEndpoint] << endl;
    // cout << "Rivalscow part: " << ((ld)rivalsCows[rightCow]-position)/2 << endl;

    if (position + ((ld)rivalsCows[rightCow]-position)/2 - rightEndpoint < 1e-9) {
        rightEndpoint--;
    }
    cout << "left: " << leftEndpoint << " right: " << rightEndpoint << endl;

    if (leftEndpoint == 0) {
        return tastinessPS[rightEndpoint];
    }
    return tastinessPS[rightEndpoint] - tastinessPS[(leftEndpoint-1)];
}

void solve() {
    int k, m, n;
    cin >> k >> m >> n;
    vector<int> positions(k);
    vector<int> tastiness(k);
    vector<ll> tastinessPrefixSum(k);
    vector<int> rivalsCows(m);
    vector<int> intervals(m+1, 0);
    vector<int> oneCowScoresPerInterval(m+1, 0);
    cin >> positions[0];
    cin >> tastiness[0];
    tastinessPrefixSum[0] = tastiness[0];
    for (int i=1;i<k;i++) {
        cin >> positions[i];
        cin >> tastiness[i];
        tastinessPrefixSum[i] = tastiness[i] + tastinessPrefixSum[i-1];
    }
    for (int i=0;i<m;i++) {
        cin >> rivalsCows[i];
    }

    auto start = lower_bound(positions.begin(), positions.end(), rivalsCows[0]);
    // cout << start - positions.begin() << endl;
    if (start != positions.begin() && start != positions.end()) {
        intervals[0] = tastinessPrefixSum[start-positions.begin()-1];
    }
    // cout << intervals[0] << endl;

    auto end = lower_bound(positions.begin(), positions.end(), rivalsCows[rivalsCows.size()-1]);
    
    // cout << end - positions.begin() << endl;
    if (end != positions.begin() && end != positions.end()) {
        intervals[m] = tastinessPrefixSum[k-1] - tastinessPrefixSum[end-positions.begin()-1];
        // cout << intervals[m] << endl;
    }
    for (int i=0;i<m-1;i++) {
        auto intervalStart = lower_bound(positions.begin(), positions.end(), rivalsCows[i]) - positions.begin() - 1;
        auto intervalEnd = lower_bound(positions.begin(), positions.end(), rivalsCows[i+1]) - positions.begin() - 1;
        if (intervalStart != intervalEnd) {
            intervals[i+1] = tastinessPrefixSum[intervalEnd] - tastinessPrefixSum[intervalStart];
            // cout << intervalStart << " & " << intervalEnd << endl;
            // cout << "Sum of interval: " << tastinessPrefixSum[intervalEnd] - tastinessPrefixSum[intervalStart] << endl;
        }
        ll maxOneCow = 0;
        cout << "Searching interval!" << endl;
        for (ld grass=intervalStart+1;grass<=intervalEnd;grass++) {
            maxOneCow = max(maxOneCow, getPointsFromPosition(positions[grass], maxOneCow, i, i+1, positions, tastinessPrefixSum, rivalsCows));
            cout << maxOneCow << endl;
        }
    }
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}