class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
		string p = "";
		for(int i = 0; i < n; ++i) {
			char ch = s[i];
			if('a' <= ch && ch <= 'z') p += ch;
			else if('A' <= ch && ch <= 'Z') p += tolower(ch);
			else if('0' <= ch && ch <= '9') p += ch;
		}
		return equal(p.begin(), p.end(), p.rbegin());
    }
};
