class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> previousRow(rowIndex+1);
        vector<int> currentRow(rowIndex+1);
        previousRow[0] = 0;
        int curIndex = 0;
        while (rowIndex >= curIndex) {
          currentRow[0] = 1;
          for (int i=1;i<curIndex;i++) {
            currentRow[i] = previousRow[i-1]+previousRow[i];
          }
          currentRow[curIndex] = 1;
          curIndex++;
          previousRow = currentRow;
        }
        return currentRow;
    }
};