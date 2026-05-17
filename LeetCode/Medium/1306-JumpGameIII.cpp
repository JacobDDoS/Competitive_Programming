class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int idx = q.front(); q.pop();
            if (arr[idx] == 0) return true;
            int l = idx-arr[idx], r = idx+arr[idx];
            if (l >= 0 && l < arr.size() && !visited[l]) {
                q.push(l);
                visited[l] = true;
            }
            if (r >= 0 && r < arr.size() && !visited[r]) {
                q.push(r);
                visited[r] = true;
            }
        }

        return false;
    }
};