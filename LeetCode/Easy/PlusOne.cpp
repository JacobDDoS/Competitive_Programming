class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        for (int i=digits.size()-1;i>0;i--) {
            if (digits[i] == 10) {
                digits[i-1]++;
                digits[i] = 0;
            }
        }
        if (digits[0] == 10) {
            digits[0] = 0;
            vector<int> copy = {1};
            for (auto& elm : digits) {
                copy.push_back(elm);
            }
            return copy;
        } 
        return digits;
    }
};