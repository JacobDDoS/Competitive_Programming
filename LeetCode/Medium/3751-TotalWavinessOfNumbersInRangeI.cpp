class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int num=num1;num<=num2;num++) {
            string str = to_string(num);
            for (int i=1;i<str.size()-1;i++) {
                if ((str[i]>str[i-1]&&str[i]>str[i+1]) || (str[i]<str[i-1]&&str[i]<str[i+1])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};