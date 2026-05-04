class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> st;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int maxm = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i] - 1) == mp.end()) {
                vector<int> ans;
                ans.push_back(nums[i]);
                int j = 1;
                while (mp.find(nums[i] + j) != mp.end()) {
                    ans.push_back(nums[i] + j);
                    j++;
                }
                maxm = max(maxm, (int)ans.size());
            }
        }
        return maxm;
    }
};
