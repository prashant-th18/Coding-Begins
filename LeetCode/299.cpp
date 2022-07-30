class Solution {
public:
    string getHint(string s, string g) {
        int c = 0, ic = 0;
        vector<bool> v(s.size() + 1, false);
        vector<int> vis(10, 0);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == g[i]) ++c;
            else {
                vis[g[i] - '0']++;
                v[i] = true;
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            if(v[i] && vis[s[i] - '0']) ++ic, vis[s[i] - '0']--;
        }
        return to_string(c) + "A" + to_string(ic) + "B";
    }
};
