class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> mp, mp2;
        for (char c : t) {
            mp[c]++;
        }
        int ans = INT_MAX;
        pair<int, int> ansPair = {-1, -1};
        int curr = 0, help = mp.size();
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            mp2[s[r]]++;
            if (mp.count(s[r]) && mp2[s[r]] == mp[s[r]]) {
                curr++;
            } 
            while (help == curr) {
                if (ans > r - l + 1) {
                    ans = r - l + 1;
                    ansPair = {l, r};
                }
                mp2[s[l]]--;
                if (mp.count(s[l]) && mp[s[l]] > mp2[s[l]]) {
                    curr--;
                }
                l++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(ansPair.first, ans);
    }
};
