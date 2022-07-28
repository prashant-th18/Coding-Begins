#define sz(x) ((int)x.size())
class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<string> st;
        auto getIndex = [&](int in, bool flag) -> int {
            while(in < s.size() && s[in] != '[' && s[in] != ']') {
                if(flag) {
                    if('0' <= s[in] && s[in] <= '9') ++in;
                    else break;
                }
                else {
                    if('0' <= s[in] && s[in] <= '9') break;
                    else ++in;
                }
            }
            return in;
        };
        string temp = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '[') continue;
            if(s[i] == ']') {
                string g = st.top(); st.pop();
                int num = stoi(st.top()); st.pop();
                for(int j = 0; j < num; ++j) temp += g;
                reverse(begin(temp), end(temp));
                if(sz(st)) {
                    temp += st.top(); st.pop();
                }
                if(sz(st) == 0) {
                    reverse(begin(temp), end(temp));
                    ans += temp; temp = "";
                }
                continue;
            }
            int j = getIndex(i, '0' <= s[i] && s[i] <= '9');
            st.push(s.substr(i, j - i));
            i = j - 1;
        }
        return ans;
    }
};
