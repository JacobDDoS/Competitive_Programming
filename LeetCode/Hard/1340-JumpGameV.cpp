class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<int> ans(arr.size(), 1);
        priority_queue<pair<int,int>> pq;
        for (int i=0;i<arr.size();i++) {
            pq.push(make_pair(-arr[i], i));
        }
        while (!pq.empty()) {
            pair<int, int> p = pq.top(); pq.pop();
            int m = -p.first;
            for (int ptr=p.second;ptr>=max(0,p.second-d);ptr--) {
                if (arr[ptr] > m) {
                    ans[ptr] = max(ans[ptr], ans[p.second]+1);
                }
                m = max(m, arr[ptr]);
            }
            m = -p.first;
            for (int ptr=p.second;ptr<=min((int)arr.size()-1,p.second+d);ptr++) {
                if (arr[ptr] > m) {
                    ans[ptr] = max(ans[ptr], ans[p.second]+1);
                }
                m = max(m, arr[ptr]);
            }
        }

        return *max_element(ans.begin(), ans.end());
    }
};