//Credits: https://www.youtube.com/watch?v=eTaWFhPXPz4&ab_channel=TECHDOSE
#include <bits/stdc++.h>
using namespace std;

vector<int> dsuf;

int find(int v) {
    if (dsuf[v]==-1) 
        return v;
    return find(dsuf[v]);
}

void union_op(int fromP, int toP) {
    fromP = find(fromP);
    toP = find(toP);
    dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int, int>>& edgeList) {
    for (auto& p: edgeList) {
        int fromP = find(p.first);
        int toP = find(p.second);

        if (fromP == toP) 
            return true;
        
        union_op(fromP, toP);
    }
    return false;
}

int main() {
    int e, v;
    cin >> e >> v;

    dsuf.resize(v, -1);
    vector<pair<int, int>> edgeList;
    for (int i=0;i<e;i++) {
        int f, t; cin >> f >> t;
        edgeList.push_back({f, t});
    }

    if (isCyclic(edgeList)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
}