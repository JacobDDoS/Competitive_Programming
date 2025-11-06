class Solution {
public:
    void dfs(int curId, int curPos, vector<int>& id, unordered_map<int, vector<int>>& adj) {
        if (id[curPos] != -1) return;
        id[curPos] = curId;
        for (int connection : adj[curPos]) {
            dfs(curId, connection, id, adj);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> id(c+1, -1);
        vector<bool> live(c+1, true);
        unordered_map<int, vector<int>> scc;
        unordered_map<int, vector<int>> adj;

        for (vector<int>& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int curId = 0;
        for (int i=1;i<=c;i++) {
            if (id[i] == -1) {
                curId++;
                dfs(curId, i, id, adj);
            }
            scc[id[i]].push_back(i);
        }

        for (auto& p : scc) {
            sort(p.second.begin(), p.second.end(), greater<int>());
        }

        vector<int> ans;
        for (vector<int>& query : queries) {
            if (query[0] == 2) {
                live[query[1]] = false;
                continue;
            }
            if (live[query[1]]) {
                ans.push_back(query[1]);
                continue;
            }

            while (scc[id[query[1]]].size() && !live[scc[id[query[1]]][scc[id[query[1]]].size()-1]]) {
                scc[id[query[1]]].pop_back();
            }
            
            if (scc[id[query[1]]].size() == 0) {
                ans.push_back(-1);
            } else {
                ans.push_back(scc[id[query[1]]][scc[id[query[1]]].size()-1]);
            }
        }

        return ans;

    }
};