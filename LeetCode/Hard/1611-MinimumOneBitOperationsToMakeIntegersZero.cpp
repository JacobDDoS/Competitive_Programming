class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0, cnt = 0;
        for (int i=(1<<30);i>0;i>>=1) {
            if ((n&i) && !(cnt&1)) {
                ans += (i*2)-1;
            } else if ((n&i)) {
                ans -= (i*2)-1;
            } 

            if ((n&i)) cnt++;
        }
        return ans;
    }
};