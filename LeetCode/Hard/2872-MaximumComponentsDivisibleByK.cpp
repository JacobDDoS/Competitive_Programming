class Solution {
public:
    unordered_map<int, set<int>> edgeMp;
    vector<bool> visited;
    int ans = 0;
    long long bfs(int n, vector<int>& v, int k) {
        visited[n] = true;
        long long sum = v[n];
        for (int next : edgeMp[n]) {
            if (!visited[next]) sum += bfs(next, v, k);
        }

        if (sum % k == 0) {
            ans++;
            return 0;
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for (vector<int>& edge : edges) {
            edgeMp[edge[0]].insert(edge[1]);
            edgeMp[edge[1]].insert(edge[0]);
        }

        visited = vector<bool>(n, false);

        bfs(0, values, k);
        return ans;
    }
};