class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
		unordered_map<char, char> mp;
		mp['('] = ')'; mp['{'] = '}'; mp['['] = ']';
		for(int i = 0; i < s.size(); ++i) {
			if(mp.count(s[i])) {
				st.push(mp[s[i]]);
			}
			else {
				if(st.empty()) return false;
				else if(st.top() == s[i]) st.pop();
				else break;
			}
		}
		return st.empty();
	}
};
