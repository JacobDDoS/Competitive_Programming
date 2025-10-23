class Solution {
public:
    bool hasSameDigits(string s) {
        string a = "";
        while (s.size() != 2) {
            a = "";
            for (int i=0;i<s.size()-1;i++) {
                a.push_back('0' + ((s[i]-'0' + s[i+1]-'0')%10));
            }
            s = a;
        }
        return s[0] == s[1];
    }
};