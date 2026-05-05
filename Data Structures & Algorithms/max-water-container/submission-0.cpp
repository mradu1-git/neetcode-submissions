class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size() - 1;
        int low = 0, high = n;
        int maxm = 0;
        while (low < high) {
            maxm = max(maxm, (high - low) * min(heights[high], heights[low]));
            if (heights[low] < heights[high]) {
                low++;
            } else if (heights[low] >= heights[high]) {
                high--;
            }
        }
        return maxm;
    }
};
