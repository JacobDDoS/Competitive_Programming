#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& isSafe, int node) {
        if (visited[node]) {
            return isSafe[node];
        }
        visited[node] = true;

        bool isSafeTemp = true;
        for (int i=0;i<graph[node].size();i++) {
            isSafeTemp &= dfs(graph, visited, isSafe, graph[node][i]);
        }

        isSafe[node] = isSafeTemp;
        return isSafeTemp;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited; // 0 -> unvisited, 1 -> not safe, 2 -> safe
        vector<bool> isSafe;
        vector<int> ans;
        for (int i=0;i<graph.size();i++) {
            visited.push_back(false);
            isSafe.push_back(false);
        }
        for (int i=0;i<graph.size();i++) {
            if (dfs(graph, visited, isSafe, i)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};