class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        val = min(val, minSt.empty() ? val : minSt.top());
        minSt.push(val);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
