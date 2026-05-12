class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int ans = 0, cur = 0;
        vector<pair<int,int>> v;
        for (auto task : tasks) {
            v.push_back(make_pair(task[1]-task[0], task[0]));
        }
        sort(v.begin(), v.end());
        for (int i=v.size()-1;i>=0;i--) {
            v[i].first += v[i].second;
            if (v[i].first > cur) {
                ans += (v[i].first-cur);
                cur = v[i].first;
            }
            if (v[i].second > cur) {
                ans += (v[i].second-cur);
                cur = 0;
            } else {
                cur -= v[i].second;
            }
        }

        return ans;
    }
};