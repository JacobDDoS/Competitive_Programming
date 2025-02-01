#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    set<vector<int>> curPath;

    set<vector<int>> dfsForPath(int begin, int end, map<int, set<int>>& mp) {
        if (begin == end) {
            return curPath;
        }
        for (int nodeTo : mp[begin]) {
            vector<int> curEdge = {begin, nodeTo};
            sort(curEdge.begin(), curEdge.end());
            curPath.insert(curEdge);
            mp[nodeTo].erase(begin);
            if (dfsForPath(nodeTo, end, mp).size()) {
                return curPath;
            }
            curPath.erase(curEdge);
        }
        return {};
    } 

    vector<int> dfs(int node, map<int, set<int>>& mp, vector<bool>& visited) {
        visited[node-1] = true;
        vector<int> result = {};
        for (int newNode : mp[node]) {
            if (visited[newNode-1]) {
                if (node < newNode) {
                    return {node, newNode};
                } else {
                    return {newNode, node};
                }
            } else {
                mp[newNode].erase(node);
                vector<int> dfsResult = dfs(newNode, mp, visited);
                if (dfsResult.size()==2) {
                    sort(dfsResult.begin(), dfsResult.end());
                    return dfsResult;
                }
            }
        }

        return {};
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, set<int>> mp;
        vector<bool> visited(edges.size(), false);

        for (vector<int>& edge : edges) {
            mp[edge[0]].insert(edge[1]);
            mp[edge[1]].insert(edge[0]);
        }
        vector<int> edgeInCycle = dfs(1, mp, visited);

        mp.clear();
        for (vector<int>& edge : edges) {
            mp[edge[0]].insert(edge[1]);
            mp[edge[1]].insert(edge[0]);
        }
        mp[edgeInCycle[0]].erase(edgeInCycle[1]);
        mp[edgeInCycle[1]].erase(edgeInCycle[0]);

        curPath = dfsForPath(edgeInCycle[0], edgeInCycle[1], mp);
        curPath.insert(edgeInCycle);

        for (int i=edges.size()-1;i>=0;i--) {
            vector<int>& edge = edges[i];
            if (curPath.count(edge)) {
                return edge;
            }
        }
        return {};
    }
};