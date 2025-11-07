class Solution {
public:
    bool valid(vector<long long>& windowSums, long long target, int r, long long k) {
        vector<long long> sub(windowSums.size(), 0);
        long long cur = 0;
        for (int i=0;i<windowSums.size();i++) {
            if (i-r-1 >= 0) cur -= sub[i-r-1];
            if (windowSums[i] + cur < target) {
                long long dif = target-windowSums[i]-cur;
                cur += dif;
                k -= dif;
            if (i+r < sub.size()) sub[i+r] = dif;    
            if (k < 0) return false;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        vector<long long> windowSums(stations.size(), 0);
        long long curSum = stations[0];
        int rPtr = 1;
        for (int i=0;i<stations.size();i++) {
            while (rPtr < stations.size() && rPtr <= i+r) {
                curSum += stations[rPtr++];
            }
            if (i-r-1 >= 0) curSum -= stations[i-r-1];
            windowSums[i] = curSum;
        }

        long long ans = 0;
        for (long long step=(1LL<<47);step>0;step>>=1) {
            while (valid(windowSums, ans+step, r, k)) {
                ans += step;
            }
        }
        return ans;
    }
};