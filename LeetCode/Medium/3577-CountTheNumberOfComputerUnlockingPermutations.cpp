class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long MOD = 1000000007;
        for (int i=1;i<complexity.size();i++) {
            if (complexity[i] <= complexity[0]) return 0;
        }
        long long ans = 1;
        for (int i=2;i<complexity.size();i++) {
            ans *= i;
            ans %= MOD;
        }
        return (int)ans;
    }
};