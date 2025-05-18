class Solution {
public:
    int colorTheGrid(int m, int n) {
        int MOD = 1'000'000'007;
        map<int, vector<vector<int>>> mp;
        mp[1].push_back({1});
        mp[1].push_back({2});
        mp[1].push_back({3});

        for (int i=2;i<=m;i++) {
            for (vector<int>& elm : mp[i-1]) {
                vector<int> temp, temp1;
                for (int num : elm) {
                    temp.push_back(num);
                    temp1.push_back(num);
                }

                if (elm[elm.size()-1] == 1) {
                    temp.push_back(2);
                    temp1.push_back(3);
                } else if (elm[elm.size()-1] == 2) {
                    temp.push_back(1);
                    temp1.push_back(3);
                } else {
                    temp.push_back(1);
                    temp1.push_back(2);
                }

                mp[i].push_back(temp);
                mp[i].push_back(temp1);

            }
        }

        vector<vector<int>> goodWith (mp[m].size());
        bool flag = true;
        for (int i=0;i<mp[m].size();i++) {
            for (int j=0;j<mp[m].size();j++) {
                flag = true;
                for (int k=0;k<m;k++) {
                    if (mp[m][i][k] == mp[m][j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    goodWith[i].push_back(j);
                }
            }
        }

        map<int, long long> cnt, prev;
        for (int i=0;i<mp[m].size();i++) {
            prev[i] = 1;
            cnt[i] = 0;
        }

        for (int i=1;i<n;i++) {
            cnt.clear();
            for (int firstArr=0;firstArr<mp[m].size();firstArr++) {
                for (int secondArr : goodWith[firstArr]) {
                    cnt[secondArr] += prev[firstArr];
                    cnt[secondArr] %= MOD;
                }
            }
            for (auto& pr : cnt) {
                prev[pr.first] = pr.second;
            }
        }

        int ans = 0;
        for (auto& pr : prev) {
            ans += pr.second;
            ans %= MOD;
        }

        return ans;

    }
};