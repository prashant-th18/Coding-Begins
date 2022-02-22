#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
int N = 1e6 + 10, n = 0;
vector<int> freq(N, 0);
vector<pair<int, int>> ans;
vector<int> v;
bool func(int index, int pre_sum)
{
    if(index >= n) return true;

    if(freq[v[index]] == 0) 
    {
        return func(index + 1, pre_sum);
    }

    int first = v[index], second = pre_sum - first;
    --freq[first];
    if(freq[second] != 0)
    {
        --freq[second];
        if(func(index + 1, first))
        {
            ans.push_back(pair(first, second)); return true;
        }
        else
        {
            ++freq[second];
            ++freq[first];
            return false;
        }
    }
    else
    {
        ++freq[first]; return false;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        cin >> n;
        n *= 2;
        v.assign(n, 0);
        ans.clear();
        freq.assign(N, 0);
        for (int &val : v) {
            cin >> val;
            freq[val]++;
        }
        sort(v.begin(), v.end(), greater<>());
        freq[v[0]]--;
        for(int i = 1; i < n; ++i)
        {
            // assuming ith index element will be with maxx
            int ith = v[i];
            freq[ith]--;
            if(func(1, v[0]))
            { 
                ans.push_back(pair(v[0], ith)); 
                reverse(all(ans));
                break;
            }
            else freq[ith]++;
        }
        if(sz(ans) == (n >> 1))
        {
            cout << "YES\n";
            cout << ans[0].first + ans[0].second << '\n';
            for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
        }
        else cout << "NO";
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
