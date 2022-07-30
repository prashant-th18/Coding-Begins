class Solution {
public:
    vector<vector<string>> suggestedProducts1(vector<string>& v, string s) {
        vector<vector<string>> ans;
        for(int i = 0; i < s.size(); ++i) {
            vector<string> c;
            for(int j = 0; j < v.size(); ++j) {
                if(v[j][i] == s[i]) c.push_back(v[j]);
            }
            v = c;
            sort(v.begin(), v.end());
            vector<string> t;
            for (int j = 0; j < min(3, (int)v.size()); j++) {
                t.push_back(v[j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& v, string s) {
        sort(v.begin(), v.end());
        vector<vector<string>> ans;
        string res = "";
        auto it = v.begin();
        for(char ch : s) {
            res += ch;
            it = lower_bound(it, v.end(), res);
            vector<string> temp;
            for(int i = 0; i < 3 && (i + it) != v.end(); ++i) {
                string& t = *(it + i);
                if(t.find(res) == string::npos) break;
                temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
