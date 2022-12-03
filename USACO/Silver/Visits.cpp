#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> goesTo;
vector<unsigned long long> moos;
vector<unsigned long long> lowLinkValues;
vector<bool> hasBeenVisited;

set<unsigned long long> nodes;

map<unsigned long long, unsigned long long> SCCToSmallest;
map<unsigned long long, unsigned long long> SCCShowsUp;

void dfs(unsigned long long i) {
    hasBeenVisited[i] = true;
    nodes.insert(i);

    unsigned long long goingToCow = goesTo[i];
    if (hasBeenVisited[goingToCow]) {
        if (!nodes.count(goingToCow)) {
            return;
        } else {
            lowLinkValues[i] = lowLinkValues[goingToCow];
            return;
        }
    } else {
        dfs(goingToCow);
        lowLinkValues[i] = min(lowLinkValues[i], lowLinkValues[goingToCow]);
    }
}

void solve() {
    unsigned long long n; cin >> n;
    unsigned long long ans = 0;
    for (unsigned long long i=0;i<n;i++) {
        hasBeenVisited.push_back(false);
        unsigned long long a, v; cin >> a >> v;
        goesTo.push_back(a-1);
        moos.push_back(v);
        lowLinkValues.push_back(i);
        ans += v;
    }

    for (unsigned long long i=0;i<n;i++) {
        if (hasBeenVisited[i] == false) {
            dfs(i);
        }
    }

    for (unsigned long long i=0;i<n;i++) {
        SCCShowsUp[lowLinkValues[i]]++;
        if (SCCToSmallest[lowLinkValues[i]] != 0) {
            SCCToSmallest[lowLinkValues[i]] = min(SCCToSmallest[lowLinkValues[i]], moos[i]);
        } else {
            SCCToSmallest[lowLinkValues[i]] = moos[i];
        }
    }

    for (auto& pr : SCCToSmallest) {
        if (SCCShowsUp[pr.first] > 1) {
            ans -= pr.second;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}