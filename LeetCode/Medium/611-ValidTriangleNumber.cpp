class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        vector<int> cnt(1001, 0), prefix(1001, 0);
        for (int a : nums) {
            cnt[a]++;
        }
        for (int i=1;i<=1000;i++) {
            prefix[i] = prefix[i-1] + cnt[i];
            if (cnt[i] >= 3) ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
        }
        
        for (int a=1;a<=1000;a++) {
            if (!cnt[a]) continue;
            for (int b=a+1;b<=1000;b++) {
                if (!cnt[b]) continue;
                int l=min(a,b), h=max(a,b);
                ans += cnt[l] * cnt[h] * (prefix[min(1000, l+h-1)] - prefix[h]);
                ans += cnt[l] * (cnt[h] * (cnt[h]-1) / 2);
                if (l+l > h) ans += cnt[h] * (cnt[l] * (cnt[l]-1) / 2);
            }
        }
        return ans;
    }
};