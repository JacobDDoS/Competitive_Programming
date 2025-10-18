class Solution {
public:
    int numPartitions(string& s, int k) {
        set<char> chars;
        int ptr = 0, ans = 0;
        for (;ptr<s.size();ptr++) {
            if (chars.size() == k && !chars.count(s[ptr])) {
                ans++;
                chars.clear();
                chars.insert(s[ptr]);
            } else {
                chars.insert(s[ptr]);
            }
        }
        if (chars.size()) ans++;
        return ans;
    }
    vector<int> length(string& s, int k) {
        vector<int> v(s.size(), -1);
        map<char, int> chars;
        int i=0;
        for (int j=0;j<s.size();j++) {
            chars[s[j]]++;
            while (chars.size() == k+1) {
                v[i] = (j-i);
                chars[s[i]]--;
                if (chars[s[i]] == 0) {
                    chars.erase(s[i]);
                }
                i++;
            }
        }
        for (;i<s.size();i++) {
            v[i] = (s.size()-i);
        }
        return v;
    }
    int pivot(string& s, int k, int i) {
        set<int> charsBefore, charsAfter;
        int ans = 0;
        for (int j=i-1;j>=0;j--) {
            charsBefore.insert(s[j]);
            if (charsBefore.size()==k) break;
        }
        for (int j=i+1;j<s.size();j++) {
            charsAfter.insert(s[j]);
            if (charsAfter.size()==k) break;
        }
        for (char c='a';c<='z';c++) {
            if (!charsBefore.count(c) && !charsAfter.count(c)) {
                // cout << "choosing char: " << c << endl;
                char cp = s[i];
                s[i] = c;
                ans = numPartitions(s, k);
                s[i] = cp;
                break;
            }
        }
        for (char c='a';c<='z';c++) {
            if (!charsBefore.count(c) && !ans) {
                char cp = s[i];
                s[i] = c;
                ans = numPartitions(s, k);
                s[i] = cp;
                break;
            }
        }

        // cout << "pivot on " << i << " results in ans: " << ans << endl;
        return ans;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        if (k==26 || s.size()==1) return 1;
        int ans = 0;

        vector<int> v = length(s, k);
        int maxIdx = 0;
        for (int i=0;i<v.size();i++) {
            if (v[i] > v[maxIdx]) {
                maxIdx = i;
            }
        }
        int i = maxIdx + v[maxIdx]/2;
        // cout << "middle: " << i << endl;
        // cout << "default: " << numPartitions(s, k) << endl;
        ans = max(pivot(s, k, 0), pivot(s, k, i));
        if (i != 0) ans = max(ans, pivot(s, k, i-1));
        if (i != s.size()-1) ans = max(ans, pivot(s, k, i+1));

        int maxPivots = 5, cnt = 0;
        set<char> chars;
        for (int i=0;i<s.size();i++) {
            if (chars.count(s[i])) {
                ans = max(ans, pivot(s, k, i));
                cnt++;
                if (cnt >= maxPivots) break;
                // break;
            }
            if (chars.size() == k) {
                chars.clear();
            }
            chars.insert(s[i]);
        }

        return ans;
    }
};