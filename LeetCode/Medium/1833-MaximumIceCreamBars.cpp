class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int arr[100001] = {0};
        int ans = 0;
        for (int& a : costs) arr[a]++;
        for (int i=1;i<100001;i++) {
            if (arr[i]) {
                int temp = min(arr[i], coins/i);
                coins -= temp*i;
                ans += temp;
            }
            if (coins <= i) return ans;
        }
        return ans;
    }
};