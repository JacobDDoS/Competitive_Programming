class Solution {
public:
    double distance(vector<int>& a, vector<int>& b) {
        return sqrt(pow(abs(a[0]-b[0]), 2) + pow(abs(a[1]-b[1]), 2));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (int i=0;i<points.size();i++) {
            for (int j=i+1;j<points.size();j++) {
                for (int k=j+1;k<points.size();k++) {
                    double a = distance(points[i], points[j]);
                    double b = distance(points[i], points[k]);
                    double c = distance(points[j], points[k]);
                    double s = (a+b+c)/2.0;
                    ans = max(ans, sqrt(s*(s-a)*(s-b)*(s-c)));
                }
            }
        }
        return ans;
    }
};