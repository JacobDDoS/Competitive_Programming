class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, bool> full;
        unordered_map<int, int> prev;

        set<int> temp;
        vector<int> ans(rains.size(), 1);
        int numFull = 0;
        for (int i=0;i<rains.size();i++) {
            if (rains[i] == 0) {
                temp.insert(i);
                if (temp.size() > numFull) {
                    temp.erase(temp.begin());
                }
            }
            else if (full[rains[i]]) {
                ans[i] = -1;
                auto itr = temp.lower_bound(prev[rains[i]]);
                if (itr == temp.end()) return {};
                ans[*itr] = rains[i];
                temp.erase(itr);
            } else {
                numFull++;
                ans[i] = -1;
                full[rains[i]] = true;
            }

            prev[rains[i]] = i;
        }

        return ans;
    }
};