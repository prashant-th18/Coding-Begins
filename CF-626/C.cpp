#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	string s; cin >> s;
	if(n % 2 == 1 || count(s.begin(), s.end(), '(') != n / 2) {
		cout << -1; return 0;
	}
	int cnt = 0, pos = 0, neg = 0;
	deque<char> v;
    stack<char> st;
	for(int i = 0; i < s.size(); ++i) {
		v.emplace_back(s[i]);
		if(s[i] == '(') {
            st.push('(');
			++pos;
		}
		else {
		    ++neg;
            if(!st.empty()) st.pop();
		}
		if(pos == neg) {
			pos = neg = 0;
			while(!v.empty() && v.front() == '(') v.pop_front();
			while(!v.empty() && v.back() == ')') v.pop_back();
			if(!st.empty()) cnt += v.size();
			v.clear();
            while(!st.empty()) st.pop();
		}
	}
	cout << cnt;
	return 0;
}
