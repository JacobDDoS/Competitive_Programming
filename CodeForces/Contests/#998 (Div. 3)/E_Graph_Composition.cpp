#include <bits/stdc++.h>

using namespace std;

void dfs(int curNode, unordered_map<int, unordered_set<int>>& adjList, vector<int>& dsuOfGraph, int valueToSetTo, vector<bool>& visited) {
    if (visited[curNode]) {
        return;
    }
    
    dsuOfGraph[curNode] = valueToSetTo;
    visited[curNode] = true;

    for (int newVert : adjList[curNode]) {
        dfs(newVert, adjList, dsuOfGraph, valueToSetTo, visited);
    }
}

void solve() {
    int n, fEdges, gEdges; cin >> n >> fEdges >> gEdges;
    vector<int> dsuOfF(n), dsuOfG(n);
    for (int i=0;i<n;i++) {
        dsuOfF[i] = i;
        dsuOfG[i] = i;
    }
    vector<bool> visitedF(n), visitedG(n);

    unordered_map<int, unordered_set<int>> adjListF, adjListG;
    int a, b;
    for (int i=0;i<fEdges;i++) {
        cin >> a >> b;
        a--; b--;
        adjListF[a].insert(b);
        adjListF[b].insert(a);
    }
    for (int i=0;i<gEdges;i++) {
        cin >> a >> b;
        a--; b--;
        adjListG[a].insert(b);
        adjListG[b].insert(a);
    }

    for (int i=0;i<n;i++) {
        if (!visitedF[i]) {
            dfs(i, adjListF, dsuOfF, i, visitedF);
        }

        if (!visitedG[i]) {
            dfs(i, adjListG, dsuOfG, i, visitedG);
        }
    }

    unordered_map<int, int> sizeOfDisjointSetsG, sizeOfDisjointSetsF;
    sizeOfDisjointSetsF.reserve(4*n);
    sizeOfDisjointSetsG.reserve(4*n);
    for (int i=0;i<n;i++) {
        sizeOfDisjointSetsG[dsuOfG[i]]++;
        sizeOfDisjointSetsF[dsuOfF[i]]++;
    }

    int ans = 0;
    for (int node = 0; node<n;node++) {
        bool connection = false;

        // For every edge, remove it if it connects to a set we don't want. 
        vector<int> toRemoveAfter;
        for (int nodeItCouldTravelTo : adjListF[node]) {
            // Remove edge
            if (dsuOfG[nodeItCouldTravelTo] != dsuOfG[node]) {
                adjListF[nodeItCouldTravelTo].erase(node);
                toRemoveAfter.push_back(nodeItCouldTravelTo);
                ans++;
            } else if (dsuOfG[nodeItCouldTravelTo] == dsuOfG[node]) {
                connection = true;
            }
        }

        for (int nodeItCouldTravelToToRemove : toRemoveAfter) {
            adjListF[node].erase(nodeItCouldTravelToToRemove);
        }

        // If there was a connection to the set we want, then we are fine, otherwise we are not.
        if (!connection && node != dsuOfG[node]) {
            adjListF[node].insert(dsuOfG[node]);
            adjListF[dsuOfG[node]].insert(node);
            ans++;
        } 
    }

    // Look for components that are disconnected from the main one. 
    for (int i=0;i<n;i++) {
        visitedF[i] = false;
    }

    for (int i=0;i<n;i++) {
        if (!visitedF[i]) {
            dfs(i, adjListF, dsuOfF, i, visitedF);
        }
    }

    // for (int i : dsuOfF) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i : dsuOfG) {
    //     cout << i << " ";
    // }
    // cout << endl;

    sizeOfDisjointSetsF.clear();
    for (int i=0;i<n;i++) {
        sizeOfDisjointSetsF[dsuOfF[i]]++;
    }

    ans += sizeOfDisjointSetsF.size() - sizeOfDisjointSetsG.size();

    cout << ans << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}