class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fors(26, 0);
        vector<int> fort(26, 0);
        for (char c : s) {
            fors[c - 'a']++;
        }
        for (char c : t) {
            fort[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (fors[i] != fort[i]) {
                return false;
            }
        }
        return true;
    }
};
