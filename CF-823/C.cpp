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

// *-> KISS*
int solve() {
    string s; cin >> s;
	int n = sz(s);
	vector<int> freq(10, 0);
	for(int i = 0; i < n; ++i) {
		freq[s[i] - '0']++;
	}
	int in = 0;
	auto f = [&]() {
		while(in < 10 && freq[in] == 0) ++in;
		return in;
	};
	f();
	vector<int> cnt(10, 0);
	string ans = "";
	for(int i = 0; i < n; ++i) {
		f();
		if(s[i] - '0' == in) {
			ans += s[i];
			freq[in]--;
		}
		else {
			if(in == 9) {
				while(freq[9] > 0) {
					ans += (9 + '0');
					freq[9]--;
				}
				break;
			}

			if(freq[in] == cnt[in + 1]) {
				while(freq[in] > 0) {
					ans += ((in + 1) + '0');
					--freq[in];
				}
				cnt[in + 1] = 0;
				f();
				--i;
			}
			else {
				++cnt[min((s[i] - '0') + 1, 9)];
			}

		}
	}
	for(int i = 0; i < 10; ++i) {
		ans += string(cnt[i], i + '0');
	}
	cout << ans;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
	int TET = 1;
    if(test) cin >> TET;
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
