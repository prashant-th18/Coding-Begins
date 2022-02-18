#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*


#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}

string res;
vector<string> every;
void rec(int index = 0)
{
    for(char ch = '0'; ch <= '9'; ++ch)
    {
        res[index] = ch;
        if(index == 5)
        {
            int s1 = 0, s2 = 0;
            for(int j = 0; j < 3; ++j) s1 += (res[j] - '0');
            for(int j = 3; j < 6; ++j) s2 += (res[j] - '0');
            if(s1 == s2) every.push_back(res);
        }
        else rec(index + 1);
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        string s; cin >> s;
        int ans = 6;
        res = "......";
        rec();
        for(int i = 0; i < sz(every); ++i)
        {
            int c = 0;
            for(int j = 0; j < 6; ++j)
            {
                if(s[j] != every[i][j]) ++c;
            }
            ans = min(ans, c);
        }
        cout << ans;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
