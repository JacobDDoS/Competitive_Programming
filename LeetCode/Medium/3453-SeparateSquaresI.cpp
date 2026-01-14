class Solution {
public:
    double dif(vector<vector<int>>& squares, double y) {
        double sum = 0;
        for (vector<int>& square : squares) {
            if (square[1] + square[2] <= y) {sum -= (double)square[2] * square[2];}
            else if (square[1] > y || (abs(square[1] - y) < 1e-6)) {sum += (double)square[2] * square[2];}
            else {
                sum += (((double)square[1] + square[2]) - y) * (double)square[2];
                sum -= (y - (double)square[1]) * (double)square[2];
            }
        }
        return sum;
    }
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<int, int>> yVals;
        for (vector<int>& square : squares) {
            yVals.push_back(make_pair(square[1], square[2]));
        }

        sort(yVals.begin(), yVals.end());
        int low = 0, high = yVals.size()-1, mid;
        double result;
        while (low < high) {
            mid = (low+high)/2;
            result = dif(squares, yVals[mid].first);
            if (mid == low) break;
            if (result > 0) {
                low = mid;
            } else {
                high = mid;
            }
        }
        double lowY, highY;
        if (result > 0) {
            lowY = yVals[mid].first;
            if (mid != yVals.size()-1) {highY = yVals[mid+1].first+yVals[mid+1].second;}
            else {highY = yVals[mid].first + yVals[mid].second;}
        } else {
            highY = yVals[mid].first;
            lowY = yVals[mid-1].first;
        }

        result = dif(squares, lowY);
        for (double step = (highY-lowY)/2.0; step > 1e-6; step /= 2) {
            result = dif(squares, lowY+step);
            while (result > 1e-6) {
                lowY += step;
                if (abs(result) < 1e-5) return lowY;
                result = dif(squares, lowY+step);
            }
        }

        return lowY;
    }
};