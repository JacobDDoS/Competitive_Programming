class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int p=0, m=0;
        for (string& op : operations) {
            if (op[0] == '-' || op[2] == '-') {
                m++;
            } else {
                p++;
            }
        }
        return p-m;
    }
};