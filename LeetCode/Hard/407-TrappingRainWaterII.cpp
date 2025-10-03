class Solution {
public:
    void dfs(int row, int col, int val, vector<vector<int>>& maxHeight, vector<vector<int>>& heightMap) {
        val = max(val, heightMap[row][col]);
        maxHeight[row][col] = val;
        
        // look up
        if (row != 0 && maxHeight[row-1][col] > val) {
            dfs(row-1, col, val, maxHeight, heightMap);
        }

        // look right
        if (col != maxHeight[0].size()-1 && maxHeight[row][col+1] > val) {
            dfs(row, col+1, val, maxHeight, heightMap);
        }

        // look down
        if (row != maxHeight.size()-1 && maxHeight[row+1][col] > val) {
            dfs(row+1, col, val, maxHeight, heightMap);
        }

        // look left
        if (col != 0 && maxHeight[row][col-1] > val) {
            dfs(row, col-1, val, maxHeight, heightMap);
        }
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> maxHeight = heightMap;

        int m = heightMap.size(), n = heightMap[0].size();
        for (int i=1;i<m-1;i++) {
            for (int j=1;j<n-1;j++) {
                maxHeight[i][j] = 9999999;
            }
        }

        vector<tuple<int, int, int>> perimeter;

        // top row
        for (int i=0;i<n;i++) {
            perimeter.push_back(make_tuple(heightMap[0][i], 0, i));
            // dfs(0, i, heightMap[0][i], maxHeight, heightMap);
        }

        // right column
        for (int i=1;i<m-1;i++) {
            perimeter.push_back(make_tuple(heightMap[i][n-1], i, n-1));
            // dfs(i, n-1, heightMap[i][n-1], maxHeight, heightMap);
        }

        // bottom row 
        for (int i=0;i<n;i++) {
            perimeter.push_back(make_tuple(heightMap[m-1][i], m-1, i));
            // dfs(m-1, i, heightMap[m-1][i], maxHeight, heightMap);
        }

        // left column 
        for (int i=1;i<m-1;i++) {
            perimeter.push_back(make_tuple(heightMap[i][0], i, 0));
            // dfs(i, 0, heightMap[i][0], maxHeight, heightMap);
        }

        sort(perimeter.begin(), perimeter.end());

        for (auto tup : perimeter) {
            cout << get<0>(tup) << endl;
            dfs(get<1>(tup), get<2>(tup), get<0>(tup), maxHeight, heightMap);
        }

        int ans = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                ans += max(0, maxHeight[i][j] - heightMap[i][j]);
            }
        }
        return ans;

    }
};