class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1;
        int left = 0, right = n - 1;
        while (up <= down) {
            int mid = up + (down - up) / 2;
            if (target > matrix[mid][n - 1]) {
                up = mid + 1;
            } else if (target < matrix[mid][0]) {
                down = mid - 1;
            } else {
                break;
            }
        }
        if (!(up <= down)) {
            return false;
        }
        int row = up + (down - up) / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > matrix[row][mid]) {
                left = mid + 1;
            } else if (target < matrix[row][mid]) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;

    }
};
