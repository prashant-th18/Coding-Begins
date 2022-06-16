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
    // Smallest Prime Factor (spf)
    int N = 1e6;
    vector<int> v(N, -1); // -1 means the number is prime, otherwise v[i] will be the spf of that number
    for(int i = 2; i * i < N; ++i)
    {
        if(v[i] == -1)
        {
            // Okay, so a prime number is encountered
            for(int j = i * i; j < N; j += i)
            {
                if(v[j] == -1) v[j] = i;
            }
        }
    }
    int queries; cin >> queries;
    while(queries--)
    {
        int num; cin >> num;
        vector<int> st;
        while(v[num] != -1)
        {
            st.push_back(v[num]);
            int no = v[num];
            while(num % no == 0) num /= no;
        }
        if(num != 1)
        st.push_back(num);
        for(auto val : st) cout << val << ' '; // Prints prime factors of "num"
    }
    return 0;
}
// -> Keep It Simple Stupid!
