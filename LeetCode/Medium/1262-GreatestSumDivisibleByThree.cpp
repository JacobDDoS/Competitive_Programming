class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> one, two;
        int ans = 0;
        for (int i : nums) {
            if (i % 3 == 1) {
                one.push_back(i);
            } else if (i % 3 == 2) {
                two.push_back(i);
            } 
            ans += i;
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        if (ans % 3 == 1) {
            if (one.size()>0 && two.size()>1) {
                ans -= min(one[0], two[0]+two[1]);
            } else if (one.size()>0) {
                ans -= one[0];
            } else if (two.size()>1) {
                ans -= (two[0]+two[1]);
            } else {
                for (int i : one) ans -= i;
                for (int i : two) ans -= i;
            }
        } else if (ans % 3 == 2) {
            if (two.size()>0 && one.size()>1) {
                ans -= min(two[0], one[0]+one[1]);
            } else if (two.size()>0) {
                ans -= two[0];
            } else if (one.size()>1) {
                ans -= (one[0]+one[1]);
            } else {
                for (int i : one) ans -= i;
                for (int i : two) ans -= i;
            }
        }
        return ans;
    }
};
