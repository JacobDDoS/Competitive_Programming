class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        unordered_map<int, int> mp;
        bool isNegative = numerator!=0 && (numerator < 0 ^ denominator < 0);
        if (numerator < 0) numerator *= -1;
        if (denominator < 0) denominator *= -1;
        string ans = (isNegative ? "-" : "") + to_string(numerator/denominator) + (numerator%denominator != 0 ? "." : "");
        numerator %= denominator;
        numerator *= 10;
        int pos = ans.size();
        while (true) {
            if (numerator == 0) {
                break;
            } else if (mp[numerator] != 0) {
                ans.push_back(')');
                ans.insert(mp[numerator], "(");
                break;
            }
            mp[numerator] = pos;
            int res = numerator/denominator;
            numerator %= denominator;
            numerator *= 10;
            ans += to_string(res);
            pos++;
        }
        return ans;
    }
};