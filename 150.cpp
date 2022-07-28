class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& val : tokens) {
            if(val == "*") {
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(s * f);
            }
            else if(val == "+") {
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(s + f);
            }
            else if(val == "-") {
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(f - s);
            }
            else if(val == "/") {
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(f / s);
            }
            else {
                int num = stoi(val);
                st.push(num);
            }
        }
        return st.top();
    }
};
