class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, vector<string>> mp;
        for (int i=0;i<code.size();i++) {
            bool validCode = (code[i] != ""), validBusinessLine = false;
            for (int j=0;j<code[i].size();j++) {
                if (
                    (code[i][j] - 'a' >= 0 && code[i][j] - 'z' <= 0) ||
                    (code[i][j] - 'A' >= 0 && code[i][j] - 'Z' <= 0) || 
                    (code[i][j] - '0' >= 0 && code[i][j] - '9' <= 0) ||
                    (code[i][j] == '_')
                ) {
                    continue;
                } else {
                    validCode = false;
                }
            }
            if (
                (businessLine[i] == "electronics") || 
                (businessLine[i] == "grocery") || 
                (businessLine[i] == "pharmacy") || 
                (businessLine[i] == "restaurant") 
            ) {
                validBusinessLine = true;
            }

            if (validCode && validBusinessLine && isActive[i]) {
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        for (auto& pr : mp) {
            sort(pr.second.begin(), pr.second.end());
        }

        vector<string> ans;
        for (string& s : mp["electronics"]) ans.push_back(s);
        for (string& s : mp["grocery"]) ans.push_back(s);
        for (string& s : mp["pharmacy"]) ans.push_back(s);
        for (string& s : mp["restaurant"]) ans.push_back(s);

        return ans;
    }
};