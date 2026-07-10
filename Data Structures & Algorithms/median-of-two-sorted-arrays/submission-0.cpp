class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        vector<int> vec;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                vec.push_back(nums1[i]);
                i++;
            } else {
                vec.push_back(nums2[j]);
                j++;
            }
        }
        while (i <= n - 1) {
            vec.push_back(nums1[i]);
            i++;
        }
        while (j <= m - 1) {
            vec.push_back(nums2[j]);
            j++;
        }
        if ((m + n) % 2) {
            return vec[(m + n) / 2];
        } 
            
        return (vec[(m + n) / 2] + vec[((m + n) / 2) - 1]) * 1.0 / 2;

    }
};