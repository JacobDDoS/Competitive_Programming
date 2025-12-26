class Solution {
public:
    int bestClosingTime(string customers) {
        int idx=0, t = count(customers.begin(), customers.end(), 'N'), c=0, s=customers.size()-t;
        for (int i=0;i<customers.size();i++) {
            c += customers[i] == 'N';
            int g = c + (customers.size() - (i+1) - (t-c));
            if (s > g) {
                s = g;
                idx = i+1;
            }
        }
        return idx;
    }
};