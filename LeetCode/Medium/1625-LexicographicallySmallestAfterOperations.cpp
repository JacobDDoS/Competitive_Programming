class Solution {
public:
    string rotate(string s, int b) {
        string ans = "";
        for (int i=s.size()-b;i<s.size();i++) {
            ans.push_back(s[i]);
        }
        for (int i=0;i<s.size()-b;i++) {
            ans.push_back(s[i]);
        }
        return ans;
    }

    string findLexSmallestString(string s, int a, int b) {
        int cnt = 0;
        string ans = s;
        do {
            int dif1, dif2;
            string temp = s;
            dif1 = gcd(a,10) * ((s[1]-'0')/gcd(a, 10));
            for (int i=1;i<s.size();i+=2) {
                temp[i] = (s[i]-'0'-dif1+10)%10 + '0';
            }

            if (b & 1) {
                dif2 = gcd(a,10) * ((s[0]-'0')/gcd(a, 10));
                for (int i=0;i<s.size();i+=2) {
                    temp[i] = (s[i]-'0'-dif2+10)%10 + '0';
                }
            }
            ans = min(ans, temp);
            s = rotate(s, b);
            cnt++;
        } while (cnt < (s.size()/gcd(b, s.size())));
        return ans;
    }
};