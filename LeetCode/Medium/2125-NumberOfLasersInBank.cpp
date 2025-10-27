class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cur = 0, ans = 0;
        for (string& r : bank) {
            int c = count(r.begin(), r.end(), '1');
            if (c) {
                ans += cur*c;
                cur = c;
            }
        }
        return ans;
    }
};