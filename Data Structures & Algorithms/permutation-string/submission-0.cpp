class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        unordered_map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }
        int need = mp.size();
        for (int i = 0; i < s2.length(); i++) {
            unordered_map<char, int> mp1;
            int curr = 0;
            for (int j = i; j < s2.length(); j++) {
                mp1[s2[j]]++;
                if (mp[s2[j]] < mp1[s2[j]]) {
                    break;
                }

                if (mp[s2[j]] == mp1[s2[j]]) {
                    curr++;
                }

                if (curr == need) {
                    return true;
                }
            }
        }
        return false;
    }
};
