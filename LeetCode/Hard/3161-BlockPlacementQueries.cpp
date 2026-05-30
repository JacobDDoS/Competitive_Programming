class Solution {
public:
    int n = 50'001;
    int t[100'004] = {0};
    void update(int p, int value) {
        p += n;
        t[p] = value;
        for (int i = p; i > 1; i >>= 1) {
            t[i >> 1] = std::max(t[i], t[i ^ 1]);
        }
    }

    // [l, r)
    int lookup(int l, int r) {
        int res = INT_MIN;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = std::max(res, t[l++]);
            if (r & 1) res = std::max(res, t[--r]);
        }
        return res;
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        set<int> s;
        vector<bool> ans;
        s.insert(0); s.insert(5*1e4);
        mp[0] = 0;
        mp[5*1e4+1] = 5*1e4+1;
        for (vector<int>& query : queries) {
            if (query[0] == 1) {
                if (query[1] == 5*1e4) continue;
                s.insert(query[1]);
                auto ptr = s.find(query[1]);
                ptr--;
                update(query[1], query[1]-(*ptr));
                ptr++; ptr++;
                update((*ptr), (*ptr)-query[1]);
            } else {
                auto ptr = --(s.upper_bound(query[1]));
                int temp = max(query[1]-(*ptr), lookup(0, query[1]+1));
                if (temp >= query[2]) {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};