class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> cnt(1+A.size(), 0), ans(A.size(), 0);
        int cur = 0;
        for (int i=0;i<A.size();i++) {
            cnt[A[i]]++;
            cnt[B[i]]++;
            if (A[i] == B[i]) {
                cur++;
            } else {
                if (cnt[A[i]] == 2) cur++;
                if (cnt[B[i]] == 2) cur++;
            }
            ans[i] = cur;
        }
        return ans;
    }
};