class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(100,0);
        for (int a : nums) {
            cnt[a-1]++;
        }
        int maxV = *max_element(cnt.begin(), cnt.end()), ans = 0;
        for (int a : cnt) {
            if (a == maxV) ans += maxV;
        }
        return ans;
    }
};