class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int pse = -1;
        int nxs = heights.size();
        int maxm = 0;
        st.push(0);
        for (int i = 1; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int temp = st.top();
                st.pop();
                nxs = i; pse = st.empty() ? -1 : st.top();
                maxm = max(maxm, heights[temp] * (nxs - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int temp = st.top();
            st.pop();
            nxs = heights.size(), pse = st.empty() ? -1 : st.top();
            maxm = max(maxm, heights[temp] * (nxs - pse - 1));
        }
        return maxm;
    }
};