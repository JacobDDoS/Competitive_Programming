class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> ones, zeroes;
        vector<vector<set<int>>> best(m+1, vector<set<int>>(n+1));
        for (string str : strs) {
            int o = 0, z = 0;
            for (int i=0;i<str.size();i++) {
                if (str[i] == '0') {
                    z++;
                } else {
                    o++;
                }
            }
            ones.push_back(o);
            zeroes.push_back(z);
        }

        int ans = 0;
        for (int i=m;i>=0;i--) {
            for (int j=n;j>=0;j--) {
                if ((i==m && j==n) || best[i][j].size()) {
                    int ptr = 0;
                    for (;ptr<strs.size();ptr++) {
                        if (
                            i >= zeroes[ptr] && j >= ones[ptr] 
                        && 
                            (
                                best[i-zeroes[ptr]][j-ones[ptr]].size() < best[i][j].size()+1 || 
                                ((*best[i-zeroes[ptr]][j-ones[ptr]].rbegin()) > ptr && best[i-zeroes[ptr]][j-ones[ptr]].size() == best[i][j].size()+1)
                            )
                        &&
                            best[i][j].count(ptr) == 0
                        ) {
                            best[i-zeroes[ptr]][j-ones[ptr]] = best[i][j];
                            best[i-zeroes[ptr]][j-ones[ptr]].insert(ptr);
                            ans = max(ans, (int)best[i-zeroes[ptr]][j-ones[ptr]].size());
                        }
                    }
                }
            }
        }
        return ans;
    }
};