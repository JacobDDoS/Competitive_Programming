class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[26] = {0};
        for (char a : text) {
            arr[a-'a']++;
        }
        string str = "balon";
        int ans = 9999999;
        for (char a : str) {
            if (a=='l' || a=='o') {
                ans = min(ans, arr[a-'a']/2);
            } else {
                ans = min(ans, arr[a-'a']);
            }
        }
        return ans;
    }
};