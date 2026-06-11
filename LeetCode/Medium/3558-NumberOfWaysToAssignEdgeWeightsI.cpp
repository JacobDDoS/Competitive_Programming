class Solution {
public:
    int MOD = 1e9 + 7;
    vector<long long> facts;
    long long inv(long long x) { return x <= 1 ? x : MOD - MOD / x * inv(MOD % x) % MOD; }
    int maxLength(int i, vector<bool>& v, unordered_map<int, vector<int>>& mp) {
        int length = 0;
        v[i] = true;
        for (int a : mp[i]) {
            if (!v[a]) {
                length = max(length, 1+maxLength(a, v, mp));
            }
        }
        return length;
    }
    long long calc(long long n, long long a) {
        return (facts[n]*inv(facts[a]) % MOD) * inv(facts[n-a]) % MOD; 
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<bool> v(edges.size()+2, false);
        unordered_map<int, vector<int>> mp;
        for (auto& edge: edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        int length = maxLength(1, v, mp);
        facts.push_back(1);
        for (int i=1;i<=length;i++) {
            facts.push_back((facts[i-1]*i)%MOD);
        }
        int ans = 0;
        if (length & 1) {
            for (int i=0;i<=length;i+=2) {ans += calc(length, i); ans %= MOD;}
        } else {
            for (int i=1;i<=length;i+=2) {ans += calc(length, i); ans %= MOD;}
        }
        return ans;
    }
};