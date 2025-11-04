class Solution {
public:
    int xSum(map<int, int>& mp, int x) {
        vector<pair<int, int>> v;
        for (auto pr : mp) {
            v.push_back(make_pair(pr.second, pr.first));
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        for (int i=0;i<min(x, (int)v.size());i++) {
            ans += v[i].first * v[i].second;
        }
        return ans;
        
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        map<int, int> mp;
        for (int i=0;i<nums.size()-k+1;i++) {
            if (i == 0) {
                for (int j=i;j<=i+k-1;j++) {
                    mp[nums[j]]++;
                } 
            } else {
                mp[nums[i-1]]--;
                mp[nums[i+k-1]]++;
            }
            int xSumOfTemp = xSum(mp, x);
            ans.push_back(xSumOfTemp);
        }
        return ans;
    }
};