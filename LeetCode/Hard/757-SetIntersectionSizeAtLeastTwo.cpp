class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        unordered_map<int, int> idxMp;
        set<int> allNumbers;
        vector<vector<int>> trueIntervals;
        map<pair<int, int>, bool> seenMp;
        for (int i=0;i<intervals.size();i++) {
            bool flag = false, dup = false;
            for (int j=0;j<intervals.size();j++) {
                if (i == j) continue;
                if (intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]) {
                    if (intervals[j][0] == intervals[i][0] && intervals[i][1] == intervals[j][1] && 
                        !seenMp[make_pair(intervals[i][0], intervals[i][1])]
                    ) {
                        dup = true;
                        continue;
                    }
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                if (dup) {
                    seenMp[make_pair(intervals[i][0], intervals[i][1])] = true;
                }
                trueIntervals.push_back(intervals[i]);
            }
        }
        intervals = trueIntervals;
        for (vector<int>& interval : intervals) {
            allNumbers.insert(interval[0]);
            allNumbers.insert(interval[1]);
        }

        int idx = 0;
        for (int number : allNumbers) {
            idxMp[number] = idx;
            idx++;
        }

        for (vector<int>& interval : intervals) {
            interval[0] = idxMp[interval[0]];
            interval[1] = idxMp[interval[1]];
        }

        sort(intervals.begin(), intervals.end());
        int ans = 2;

        int l = intervals[0][1]-1, r=intervals[0][1];
        for (int i=1;i<intervals.size();i++) {
            if (intervals[i][0] <= l && intervals[i][1] >= r) continue;
            if (intervals[i][0] <= r && r <= intervals[i][1]) {
                l = r;
                r = intervals[i][1];
                ans++; 
            } else {
                l = intervals[i][1]-1;
                r = intervals[i][1];
                ans+=2;
            }
        }

        return ans;

    }
};