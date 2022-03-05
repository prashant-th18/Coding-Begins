#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    int N = 1e4;
    vector<bool> pr(N, true);
    vector<int> prime, compo;
    prime.push_back(2);
    pr[0] = pr[1] = false;
    for(int i = 4; i < N; i += 2)
    {
        pr[i] = false;
    }
    for(int i = 3; i < N; i += 2)
    {
        if(pr[i])
        {
            prime.push_back(i);
            for(int j = i * i; j < N; j += 2 * i)
            {
                pr[j] = false;
            }
        }
    }
    for(int i = 1; i < N; ++i)
    {
        if(!pr[i])
        {
            compo.push_back(i);
        }
    }
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        int sum = n;
        int j = 0;
        while(1)
        {
            if(pr[sum])
            {
                vector<int> temp;
                for(int i = 0; i < n - 1; ++i)
                {
                    temp.push_back(1);
                }
                temp.push_back(compo[j]);
                int cnt = n;
                while(cnt > 0)
                {
                    for(auto val : temp)
                    {
                        cout << val << ' ';
                    }
                    cout << '\n';
                    rotate(temp.begin(), temp.begin() + 1, temp.end());
                    --cnt;
                }
                break;
            }
            else
            {
                sum = n - 1 + compo[++j];
            }
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!

