class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i=1;i<words.size();i++) {
            string temp = ans[ans.size()-1], temp1 = words[i];
            sort(temp.begin(), temp.end());
            sort(temp1.begin(), temp1.end());
            if (temp1 == temp) continue;
            ans.push_back(words[i]);
        }
        return ans;
    }
};