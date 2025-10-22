class Solution {
public:
    int elementsInRange(vector<int>& v, int low, int high) {
        return (upper_bound(v.begin(), v.end(), high) - lower_bound(v.begin(), v.end(), low));
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, int> cnt;
        unordered_set<long long> s;
        s.reserve(nums.size() * 3);
        cnt.reserve(nums.size());
        for (int elm : nums) {
            s.insert(elm-k);
            s.insert(elm+k);
            s.insert(elm);
            cnt[elm]++;
        }
        int ans = 0;
        for (long long num : s) {
            ans = max(ans, min(cnt[num]+numOperations, elementsInRange(nums, num-k, num+k)));
        }
        return ans;
    }
};