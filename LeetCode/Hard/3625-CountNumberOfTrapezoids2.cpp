class Solution {
public:
    int INF = INT_MAX;
    int countTrapezoids(vector<vector<int>>& points) {
        int ans = 0;
        // slope -> y-int -> count
        unordered_map<double, map<double, int>> mp;

        // slope -> length -> y-int -> count
        unordered_map<double, map<double, map<double, int>>> lengths;

        long long roundTo = 10000000;
        for (int i=0;i<points.size();i++) {
            for (int j=i+1;j<points.size();j++) {
                if (i == j) continue;
                if (points[i][0] == points[j][0]) {
                    mp[INF][points[i][0]]++;

                    double length = sqrt(pow(((points[i][0]-points[j][0])), 2) + pow((points[i][1]-points[j][1]), 2));
                    length = round(length*roundTo) / roundTo;
                    lengths[INF][length][points[i][0]]++;
                } else {
                    double slope = ((double)points[i][1]-(double)points[j][1])/((double)points[i][0] - (double)points[j][0]);
                    double yAtZero = -slope * points[i][0] + points[i][1];
                    double length = sqrt(pow(((points[i][0]-points[j][0])), 2) + pow((points[i][1]-points[j][1]), 2));
                    slope = round(slope*roundTo) / roundTo;
                    yAtZero = round(yAtZero*roundTo) / roundTo;
                    length = round(length*roundTo) / roundTo;
                    mp[slope][yAtZero]++;
                    lengths[slope][length][yAtZero]++;
                }
            }
        }

        int para = 0;
        for (auto& pr : mp) {
            double slope = pr.first;
            int total = 0;
            for (auto& slopePr : pr.second) {
                total += slopePr.second;
            }

            for (auto& lengthsPr : lengths[slope]) {
                int same = 0;
                for (auto& yIntsPr : lengthsPr.second) {
                    same += yIntsPr.second;
                    para -= yIntsPr.second * (yIntsPr.second-1) / 2;
                }
                para += same * (same-1) / 2;
            }

            for (auto& slopePr : pr.second) {
                ans += (total-slopePr.second)*slopePr.second;
            }
        }

        return ans / 2 - para / 2;

    }
};