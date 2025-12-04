class Solution {
public:
    int countCollisions(string directions) {
        int l = 0, r = directions.size()-1;
        while (l < directions.size() && directions[l] == 'L') l++;
        while (r >= 0 && directions[r] == 'R') r--;
        int ans = 0;
        for (int i=l;i<=r;i++) {
            if (i+1 <= r && directions[i] == 'R' && directions[i+1] == 'L') {
                ans += 2;
                i++;
            } else if (directions[i] != 'S') {
                ans++;
            }
        }
        return ans;
    }
};