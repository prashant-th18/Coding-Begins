class Solution {
public:
    int n;
    vector<string> ans;
    void generate(string till, int index, int l = 0) {
        if(index > n) {
            if(l == 0)
            ans.emplace_back(till);
            return;
        }
        if(l) {
           generate(till + ')', index + 1, l - 1);
        }
        generate(till + '(', index + 1, l + 1);
    }
    vector<string> generateParenthesis(int m) {
        n = m * 2;
        generate("", 1);
        return ans;
    }
};
