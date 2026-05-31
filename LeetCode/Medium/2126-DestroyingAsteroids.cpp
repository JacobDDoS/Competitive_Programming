class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long cur = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int a : asteroids) {
            if (a > cur) return false;
            else cur += a;
        }
        return true;
    }
};