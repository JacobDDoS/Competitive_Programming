class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);

        unordered_map<int, bool> mp;
        for (int i=0;i<hFences.size();i++) {
            for (int j=i+1;j<hFences.size();j++) {
                mp[abs(hFences[j] - hFences[i])] = true;
            }
        }

        long long ans = -1;
        for (int i=0;i<vFences.size();i++) {
            for (int j=i+1;j<vFences.size();j++) {
                if (mp[abs(vFences[j] - vFences[i])]) {
                    ans = max(ans, ((long long)vFences[j]-vFences[i]) * ((long long)vFences[j]-vFences[i]));
                }
            }
        } 

        return ans % 1000000007;
    }
};