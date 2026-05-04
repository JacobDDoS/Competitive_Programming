class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for (int a=0;a<r;a++) {
            for (int b=a;b<c-1-a;b++) {
                int temp, curA = a, curB = b, next = matrix[a][b];
                for (int i=0;i<4;i++) {
                    temp = matrix[curB][c-1-curA];
                    matrix[curB][c-1-curA] = next;
                    next = temp;
                    swap(curA, curB);
                    curB = c-1-curB;
                }
            }
        }
    }
};