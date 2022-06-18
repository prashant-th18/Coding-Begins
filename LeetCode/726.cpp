class Solution {
public:
    map<string, int> mp;
    void func(string& s, int& index, int ans) {
        int temp = 1;
        while(index >= 0 && s[index] != '(') {
            if('0' <= s[index] && s[index] <= '9') {
                int i = index - 1;
                while('0' <= s[i] && s[i] <= '9') --i;
                ++i;
                temp = stoi(s.substr(i, index - i + 1));
                index = i - 1;
            }
            else if(s[index] == ')') {
                index--;
                func(s, index, ans * temp);
                temp = 1;
            }
            else {
                string n = "";
                int i = index;
                while(isupper(s[i]) == false) n += s[i--];
                n += s[i--];
                reverse(n.begin(), n.end());
                mp[n] += temp * ans;
                temp = 1;
                index = i;
            }
        }
        --index;
    }
    string countOfAtoms(string formula) {
        formula = "(" + formula + ")";
        int in = formula.size() - 1;
        func(formula, in, 1);
        string res = "";
        for(auto val : mp) {
            res += val.first;
            if(val.second != 1) res += to_string(val.second);
        }
        return res;
    }
};
