#include <bits/std++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        // vector<int> color(limit+1, 0);
        unordered_map<int, int> color;
        unordered_map<int, int> mp;
        int curAns = 0;
        for (int i=0;i<queries.size();i++) {
            if (color[queries[i][0]]) {
                if (--mp[color[queries[i][0]]] == 0) {
                    curAns--;
                }
            }
            if (++mp[queries[i][1]] == 1) {
                curAns++;
            }
            color[queries[i][0]] = queries[i][1];

            ans[i] = curAns;
        }

        return ans;
    }
};