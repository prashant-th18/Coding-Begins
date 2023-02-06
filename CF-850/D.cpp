#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// Use -> unordered_map<key_type, value_type, custom_hash> mp;
using pll = pair<int, int>;
// *-> KISS*
int solve() {
    int m; cin >> m;
    vector<unordered_map<char, int, custom_hash>> v(m);
    
    // set<pll, greater<pll>> w, i, n;
    map<string, set<int>> st;
    vector<string> here(m);
    
    for(int ii = 0; ii < m; ++ii) {
    	string s; cin >> s;
    	string ok = "";
    	int c1 = count(all(s), 'w');
    	// if(c1 > 1) w.insert({c1, ii});
    	v[ii]['w'] = c1;
    	int c2 = count(all(s), 'i');
    	// if(c2 > 1) i.insert({c2, ii});
    	v[ii]['i'] = c2;
    	int c3 = count(all(s), 'n');
    	// if(c3 > 1) n.insert({c3, ii});
    	v[ii]['n'] = c3;
    	ok += string(c1, 'w');
    	ok += string(c2, 'i');
    	ok += string(c3, 'n');
    	sort(all(ok));
    	st[ok].insert(ii);
    	here[ii] = ok;
    }
    auto returnCnt = [&](int in) -> unordered_map<char, int, custom_hash> {
    	unordered_map<char, int, custom_hash> cnt;
    	for(int i = 0; i < 3; ++i) {
    		cnt[here[in][i]]++;
    	}
    	return cnt;    	
    };
    map<pair<int, int>, pair<char, char>> ans;
    map<char, int> index;
    index['i'] = 0, index['n'] = 1, index['w'] = 2;
    map<int, char> rev;
    rev[0] = 'i', rev[1] = 'n', rev[2] = 'w';
    for(int i = 0; i < m; ++i) {
    	auto temp = returnCnt(i);
    	if(sz(temp) == 3) {}
    	else if(sz(temp) == 2) {
    		string& s = here[i];
    		st[s].erase(i);
    		// 'i', 'n', 'w'
    		vector<int> h(3);
    		for(int j = 0; j < 3; ++j) {
    			h[index[s[j]]]++;
    		}
    		char two, no, one;
    		for(int ii = 0; ii < 3; ++ii) {
    			if(h[ii] == 2) two = rev[ii];
    			if(h[ii] == 0) no = rev[ii];
    			if(h[ii] == 1) one = rev[ii];
    		}
    		{
    			string z;
    			z += no; z += no; z += no;
    			if(sz(st[z])) {
    				auto p = *st[z].begin(); st[z].erase(p);
    				here[i] = "win";
    				z[0] = two;
    				sort(all(z));
    				st[z].insert(p);
    				ans[{i, p}] = {two, no};
    				continue;
    			}
    		}
    		{
    			string z;
    			z += no; z += no; z += one;
    			sort(all(z));
    			if(sz(st[z])) {
    				auto p = *st[z].begin(); st[z].erase(p);
    				here[i] = "win";
    				z = "win";
    				ans[{i, p}] = {two, no};
    				continue;
    			}
    		}
    	}
    	else {
    		string& s = here[i];
    		st[s].erase(i);
    		vector<int> h(3);
    		for(int j = 0; j < 3; ++j) {
    			h[index[s[j]]]++;
    		}
    		char no = '.', no1 = '.', t;
    		for(int ii = 0; ii < 3; ++ii) {
    			if(h[ii] == 0 && no == '.') no = rev[ii];
    			if(h[ii] == 0 && no != '.') no1 = rev[ii];
    			if(h[ii] == 3) t = rev[ii];
    		}
    		// iii
    		{
    			string z;
    			z += no; z += no; z += no;
    			sort(all(z));
    			if(sz(st[z])) {
    				auto p = *st[z].begin(); st[z].erase(p);
    				here[i][0] = no;
    				here[p][0] = t;
    				ans[{i, p}] = {t, no};
    				sort(all(here[i]));
    				sort(all(here[p]));
    				st[here[i]].insert(i);
    				st[here[p]].insert(p);
    				--i;
    				continue;
    			}
    		}
    		{
    			string z;
    			z += no1; z += no1; z += no1;
    			sort(all(z));
    			if(sz(st[z])) {
    				auto p = *st[z].begin(); st[z].erase(p);
    				here[i][0] = no1;
    				here[p][0] = t;
    				ans[{i, p}] = {t, no1};
    				sort(all(here[i]));
    				sort(all(here[p]));
    				st[here[i]].insert(i);
    				st[here[p]].insert(p);
    				--i;
    				continue;
    			}
    		}
    		// nnw
    		// iii
    		{
    			string z;
    			z += no; z += no; z += no1;
    			sort(all(z));
    			if(sz(st[z])) {
    				auto p = *st[z].begin(); st[z].erase(p);
    				here[i][0] = no;
    				here[p] = "win";
    				ans[{i, p}] = {t, no};
    				sort(all(here[i]));
    				sort(all(here[p]));
    				st[here[i]].insert(i);
    				// st[here[p]].insert(p);
    				--i;
    				continue;
    			}
    		}
    		{
    			string z;
    			z += no1; z += no1; z += no;
    			sort(all(z));
    			if(sz(st[z])) {
    				auto p = *st[z].begin(); st[z].erase(p);
    				here[i][0] = no1;
    				here[p] = "win";
    				ans[{i, p}] = {t, no1};
    				sort(all(here[i]));
    				sort(all(here[p]));
    				st[here[i]].insert(i);
    				// st[here[p]].insert(p);
    				--i;
    				continue;
    			}
    		}
    	}
    }
    cout << sz(ans) << '\n';
    for(const auto& [x, y] : ans) {
    	cout << x.ff << ' ' << y.ff << ' ' << x.ss << ' ' << y.ss << '\n';
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif
        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!