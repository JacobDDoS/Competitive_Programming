class Solution {
public:
    bool areFriends(int a, int b, unordered_map<int, bitset<500>>& mp) {
        a--; b--;
        return (mp[a]&mp[b]).count() > 0;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, bitset<500>> mp, curMp;
        int m = languages.size();
        int ans = 500, temp = 0;
        for (int i=0;i<m;i++) {
            for (int language : languages[i]) {
                mp[i].flip(language-1);
            }
        }

        for (int i=1;i<=n;i++) {
            temp = 0;
            curMp = mp;
            for (vector<int>& friends : friendships) {
                if (areFriends(friends[0], friends[1], curMp)) continue;
                
                temp += 2;

                if (curMp[friends[0]-1][i-1]) {
                    temp--;    
                } else {
                    curMp[friends[0]-1].flip(i-1);
                }

                if (curMp[friends[1]-1][i-1]) {
                    temp--;
                } else {
                    curMp[friends[1]-1].flip(i-1);
                }
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};