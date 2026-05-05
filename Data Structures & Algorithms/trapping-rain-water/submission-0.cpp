class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        prefixMax[0] = height[0];
        suffixMax.back() = height.back();
        int total = 0;
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }
        for (int i = 0; i < n; i++) {
            total += min(suffixMax[i], prefixMax[i]) - height[i];
        }
        return total;
    }
};
