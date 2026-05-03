class Solution {
public:
    void leftRotation(string& s) {
        char c = s[0];
        for (int i=0;i<s.size()-1;i++) {
            s[i] = s[i+1];
        }
        s[s.size()-1] = c;
    }
    bool rotateString(string s, string goal) {
        for (int i=0;i<s.size();i++) {
            if (s == goal) return true;
            leftRotation(s);
        }
        return false;
    }
};