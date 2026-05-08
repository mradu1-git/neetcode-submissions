class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false;
        stack<char> st;
        for (char c : s) {
            if (c == '{' || c == '(' || c == '[') {
                st.push(c);
            } else if (c == '}') {
                if (st.empty()) return false;
                if (st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (st.empty()) return false;
                if (st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                if (st.empty()) return false;
                if (st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
