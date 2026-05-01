class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec;
        for (auto pair: mp) {
            vec.push_back({pair.second, pair.first});
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        reverse(vec.begin(), vec.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};
