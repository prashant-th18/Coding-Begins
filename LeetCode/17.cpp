#include<bits/stdc++.h>
class Solution {
public:
    
    unordered_map<char, vector<char>> mp {{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
    vector<string> ans;
    void generate(string till, int index, string& dig) {
        if(index == dig.size()) {
            ans.emplace_back(till);
            return;
        }
        for(auto &v: mp[dig[index]]) {
            generate(till + v, index + 1, dig);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        generate("", 0, digits);
        return ans;
    }
};

