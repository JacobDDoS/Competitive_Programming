class Solution {
public:
    bool valid(int n) {
        bool good = true, flag = false;
        while (n != 0) {
            int digit = n%10;
            if (digit == 3 || digit == 4 || digit == 7) {
                good = false;
                break;
            } else if (digit == 2 || digit == 5 || digit == 6 || digit == 9) flag = true;
            n/=10;
        }
        return (good&&flag);
    }
    int rotatedDigits(int n) {
        static vector<int> cnt;
        if (cnt.size() != 10000) {
            for (int i=1;i<=10000;i++) {
                cnt.push_back(valid(i) + (i!=1 ? cnt[i-2] : 0));
            }
        }
        return cnt[n-1];
    }
};