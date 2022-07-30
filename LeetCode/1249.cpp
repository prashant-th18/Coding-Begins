#define sz(x) ((int)x.size())
class Solution {
public:
    string minRemoveToMakeValid(string s) {
       int n = s.size();
       vector<bool> vis(n, true);
       stack<int> st;
       for (int i = 0; i < n; i++) {
           if(s[i] != '(' && s[i] != ')') continue;
           else if(s[i] == '(') {
               st.push(i);
           }
           else {
               if(sz(st) && s[st.top()] == '(') st.pop();
               else st.push(i);
           }
       }
       while(sz(st)) {
           vis[st.top()] = false;
           st.pop();
       }
       string p = "";
       for (int i = 0; i < n; i++) {
           if(vis[i]) p += s[i];
       }
       return p;
    }
};
