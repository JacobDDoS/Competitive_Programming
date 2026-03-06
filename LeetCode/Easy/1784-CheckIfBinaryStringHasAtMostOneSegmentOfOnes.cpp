class Solution {
public:
    bool checkOnesSegment(string s) {
        bool f = true;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '1') {
                if (f) continue;
                else return false;
            } else {
                if (f) f = false;
                else continue;
            }
        }
        return true;
    }
};