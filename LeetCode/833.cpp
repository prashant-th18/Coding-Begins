#define all(x) x.begin(), x.end()
class Solution {
public:
    string findReplaceString(string s, vector<int>& ind, vector<string>& src, vector<string>& tar) {
        map<int, vector<string>> mp;
        for(int i = 0; i < ind.size(); ++i) {
            mp[ind[i]].push_back(src[i]);
            mp[ind[i]].push_back(tar[i]);
        }
        ind.clear(); src.clear(); tar.clear();
        for(auto val : mp) {
            ind.push_back(val.first);
            src.push_back(val.second[0]);
            tar.push_back(val.second[1]);
        }
        reverse(all(ind)); reverse(all(src)); reverse(all(tar));
        int i = 0, n = s.size();
        string res = "";
        while(i < n) {
            if(ind.size() != 0) {
                if(ind.back() == i) {
                    // Checking
                    int ts = src.back().size();
                    if(i + ts <= n && s.substr(i, ts) == src.back()) {
                        i += ts;
                        res += tar.back();
                    }
                    else {
                        res += s[i++];
                    }
                    tar.pop_back(); src.pop_back(); ind.pop_back();
                }
                else {
                    res += s[i++];
                }
            }
            else res += s[i++];
        }
        return res;
    }
};
