class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int, int>> v;
        int ans = 0;
        for (int i=0;i<height.size();i++) {
            for (auto& pr : v) {
                ans = max(ans, (i-pr.first)*min(height[i], pr.second));
            }
            pair<int, int> pr = make_pair(i, height[i]);
            if (!v.size() || v[v.size()-1].second < height[i]) {
                v.push_back(pr);
            }
        }
        return ans;
    }
};