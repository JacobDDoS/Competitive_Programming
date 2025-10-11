class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        vector<pair<int, long long>> prs;
        vector<long long> best;
        sort(power.begin(), power.end());
        for (int i : power) {
            if (!prs.size() || prs[prs.size()-1].first < i) {
                prs.push_back(make_pair(i, i));
            } else {
                prs[prs.size()-1].second += i;
            }
        }

        best = vector<long long>(prs.size(), 0);
        for (int i=0;i<prs.size();i++) {
            long long k = prs[i].first, v = prs[i].second;
            if (i != 0) best[i] = best[i-1];

            int j = i;
            while (j >= 0 && prs[j].first > k-3) {
                j--;
            }
            if (j != -1) {
                best[i] = max(best[i], best[j] + v);
            } else {
                best[i] = max(best[i], v);
            }
        }
        
        return best[best.size()-1];
    }
};