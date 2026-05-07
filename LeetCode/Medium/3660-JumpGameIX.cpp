class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        stack<int> inc;
        inc.push(nums[0]);
        for (int i=1;i<nums.size();i++) {
            if (nums[i] >= inc.top()) {
                inc.push(nums[i]);
            }
        }
        vector<int> ans(nums.size(), 0);
        vector<pair<int, int>> dec;
        for (int i=nums.size()-1;i>=0;i--) {
            auto ptr = upper_bound(dec.begin(), dec.end(), make_pair(inc.top(), 0), std::greater<pair<int,int>>());
            if (ptr != dec.end()) ans[i] = max(inc.top(), ans[(*ptr).second]);
            else ans[i] = inc.top();

            if (nums[i] == inc.top()) inc.pop();
            if (dec.size() == 0 || nums[i] < dec[dec.size()-1].first) dec.push_back(make_pair(nums[i], i));
        }
        return ans;
    }
};