class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (string s : strs) {
            vector<int> vec(26);
            for (char c : s) {
                vec[c - 'a']++;
            }
            string temp = to_string(vec[0]);
            for (int i= 1; i < 26; i++) {
                temp += ',' + to_string(vec[i]);
            }
            res[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto pair : res) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
