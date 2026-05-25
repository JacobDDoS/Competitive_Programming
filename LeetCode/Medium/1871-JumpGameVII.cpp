class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s[s.size()-1] == '1') return false;
        set<int> st;
        for (int i=1;i<s.size();i++) {
            st.insert(i);
        }
        stack<int> q;
        q.push(0);
        vector<int> marked;
        while (!q.empty()) {
            int idx = q.top(); q.pop();
            if (idx == s.size()-1) return true;
            for (auto itr=st.lower_bound(idx+minJump);itr!=st.end() && (*itr)<=idx+maxJump;++itr) {
                marked.push_back(*itr);
                if (s[*itr] == '0') q.push(*itr);
            }
            for (int a : marked) {
                st.erase(a);
            }
            marked = {};
        }
        return false;
    }
};