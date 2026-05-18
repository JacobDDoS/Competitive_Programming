class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> visitedMp;
        vector<bool> visited(arr.size(), false);
        for (int i=0;i<arr.size();i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> q, p;
        q.push_back(0);
        visited[0] = true;
        int cur = 0;
        while (q.size()) {
            for (int a : q) {
                if (a == arr.size()-1) return cur;
                if (a != 0 && !visited[a-1]) {
                    p.push_back(a-1);
                    visited[a-1] = true;
                }
                if (!visited[a+1]) {
                    p.push_back(a+1);
                    visited[a+1] = true;
                }
                if (!visitedMp[arr[a]]) {
                    for (int b : mp[arr[a]]) {
                        if (!visited[b]) {
                            p.push_back(b);
                            visited[b] = true;
                        }
                    }
                    visitedMp[arr[a]] = true;
                }
            }
            cur++;
            q = p;
            p = {};
        }
        return -1;
    }
};