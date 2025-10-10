class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = -999999999;
        for (int i=0;i<energy.size();i++) {
            if (i-k < 0) {
                ;
            } else {
                energy[i] = max(energy[i], energy[i-k]+energy[i]);
            }

            if (i >= energy.size()-k) ans = max(ans, energy[i]);
        }

        return ans;
    }
};