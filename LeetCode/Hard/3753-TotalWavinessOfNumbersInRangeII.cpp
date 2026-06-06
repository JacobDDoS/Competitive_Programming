class Solution {
public:
    long long calc(long long num) {
        if (num <= 100) return 0;
        string numStr = to_string(num), n = "";
        int l = (int)numStr.size();
        for (int i=0;i<16-numStr.size();i++) {
            n.push_back('0');
        }
        n += numStr;
        long long dp[16][15][10][3][2][2] = {0};

        if (n[0] == '0') {
            dp[15][0][0][2][1][0] = 1;
        } else {
            dp[15][0][0][2][0][0] = 1;
            dp[15][0][1][2][1][1] = 1;
        }
        
        // Remaining digits
        for (int a=15;a>0;a--) {
            // All possible total values of peaks and valleys
            for (int b=0;b<15;b++) {
                // Last Digit
                for (int c=0;c<10;c++) {
                    // Did last digit increase, decrease, or is N/A compared to the digit before it
                    for (int d=0;d<3;d++) {
                        // Is the value on edge?
                        for (int e=0;e<2;e++) {
                            // Have we had a non-zero value yet?
                            for (int f=0;f<2;f++) {
                                if (!dp[a][b][c][d][e][f]) continue;
                                int upTo = (e == 1 ? n[16-a] - '0' : 9);
                                for (int g=0;g<=upTo;g++) {
                                    bool doesTotalIncrease = (f==1) && ((d==1 && g > c) || (d==0 && g < c));
                                    int newTotal = b + (int)doesTotalIncrease;
                                    int newDir = f == 0 ? 2 : (c > g ? 1 : (c < g ? 0 : 2));
                                    int onEdge = (e==1 && g==upTo);
                                    int haveRealNumberYet = (f==1) || (g != 0);
                                    dp[a-1][newTotal][g][newDir][onEdge][haveRealNumberYet] += dp[a][b][c][d][e][f];
                                }
                            }
                        }
                    }
                }
            }
        }

        long long ans = 0;
        for (int b=1;b<15;b++) {
            for (int c=0;c<10;c++) {
                for (int d=0;d<3;d++) {
                    for (int e=0;e<2;e++) {
                        for (int f=0;f<2;f++) {
                            ans += dp[0][b][c][d][e][f] * b;
                        }
                    }
                }
            }
        }

        return ans;
    }
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1-1);
    }
};