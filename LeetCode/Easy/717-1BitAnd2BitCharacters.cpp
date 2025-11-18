class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        vector<bool> v(bits.size()+1, false);
        v[0] = true;
        for (int i=0;i<bits.size()-1;i++) {
            if (v[i]) {
                if (bits[i] == 0) {
                    v[i+1] = true;
                } else if (i+2 <= bits.size()) {
                    v[i+2] = true;
                }
            }
        }
        return !v[bits.size()];
    }
};