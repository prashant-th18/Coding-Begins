#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        stack<int> st;
        int maxx = 0;
        for(int i = 0; i < n; ++i) {
            if(st.empty()) {
                if(s[i] == '(')
                st.push(i);
            }
            else if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                assert(s[st.top()] == '(');
                int t = st.top();
                int extra = (t == 0) ? (0) : (dp[t - 1]);
                int here = i - st.top() + 1 + extra;
                maxx = max(maxx, here);
                dp[i] = here;
                st.pop();
            }
        }
        return maxx;
    }
};
int main() {
    Solution s;
    string res = ")()())()()(";
    s.longestValidParentheses(res);
    return 0;
}
