class Solution {
public:
    int solve(int a, int b, string op) {
        if (op == "+") return b + a;
        if (op == "-") return b - a;
        if (op == "*") return b * a;
        if (op == "/") return b / a;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(solve(a, b, s));
            } else {
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};