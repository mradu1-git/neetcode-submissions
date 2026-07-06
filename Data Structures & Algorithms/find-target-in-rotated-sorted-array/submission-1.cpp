class Solution {
public:
    int findMinIndex(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int minIdx = findMinIndex(nums);
        int low = 0, high = n - 1;

        if (target >= nums[minIdx] && target <= nums[high]) {
            low = minIdx;
        } else {
            high = minIdx - 1;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};