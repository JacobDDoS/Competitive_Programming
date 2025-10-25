class Solution {
public:
    vector<int> nums;
    vector<int> calculate() {
        vector<int> ans;
        vector<string> starting = {"1", "22", "122", "333", "1333", "4444", "14444", "22333", "55555", "122333", "155555", "224444","666666"};
        for (string str : starting) {
            do {
                ans.push_back(stoi(str));
            } while (next_permutation(str.begin(), str.end()));
        }

        sort(ans.begin(), ans.end());
        ans.push_back(1224444);
        return ans;
    }
    int nextBeautifulNumber(int n) {
        if (!nums.size()) nums = calculate();
        return *upper_bound(nums.begin(), nums.end(), n);
    }
};