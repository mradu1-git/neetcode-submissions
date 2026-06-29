class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            vec1[s1[i] - 'a']++;
            vec2[s2[i] - 'a']++;
        }
        int help = 0;
        for (int i = 0; i < 26; i++) {
            if (vec1[i] == vec2[i]) {
                help++;
            }
        }
        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (help == 26) {
                return true;
            }   
            vec2[s2[r] - 'a']++;
            if (vec1[s2[r] - 'a'] == vec2[s2[r] - 'a']) {
                help++;
            } else if (vec1[s2[r] - 'a'] + 1 == vec2[s2[r] - 'a']) {
                help--;
            }
            vec2[s2[l] - 'a']--;
            if (vec2[s2[l] - 'a'] == vec1[s2[l] - 'a']) {
                help++;
            } else if (vec1[s2[l] - 'a'] - 1 == vec2[s2[l] - 'a']) {
                help--;
            }
            l++;
        }
        return help == 26;
    }
};
