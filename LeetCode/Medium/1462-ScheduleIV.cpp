#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, map<int, set<int>>& mp, vector<vector<int>>& prerequisites) {

        for (int i=0;i<prerequisites.size();i++) {
            if (prerequisites[i][1] == node) {
                if (mp[prerequisites[i][0]].size()==0) {
                    dfs(prerequisites[i][0], mp, prerequisites);
                } 
                mp[node].insert(prerequisites[i][0]);
                for (auto& dependency : mp[prerequisites[i][0]]) {
                    mp[node].insert(dependency);
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        map<int, set<int>> mp;
        for (int i=0;i<numCourses;i++) {
            dfs(i, mp, prerequisites);
        }

        vector<bool> ans(queries.size(), false);
        for (int i=0;i<queries.size();i++) {
            vector<int> query = queries[i];
            ans[i] = mp[query[1]].count(query[0]);
        }

        return ans;
    }
};