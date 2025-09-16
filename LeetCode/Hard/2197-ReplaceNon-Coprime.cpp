class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> a = nums, b;
        bool flag = true, reversed = false;
        while (flag) {
            flag = false;
            for (int i=0;i<a.size()-1;i++) {
                int curGCD = gcd(a[i], a[i+1]);
                if (curGCD > 1) {
                    flag = true;
                    a[i+1] = lcm(a[i], a[i+1]);
                    a[i] = 0;
                }
            }
            if (!flag) {
                if (reversed) {
                    reverse(a.begin(), a.end());
                }
                return a;
            }
            b.clear();
            for (int i=0;i<a.size();i++) {
                if (a[i]) {
                    b.push_back(a[i]);
                }
            }
            a = b;
            reverse(a.begin(), a.end());
            reversed = !reversed;
        }
        return {};
    }
};