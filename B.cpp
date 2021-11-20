#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        deque<int> dq, bq;
        for (int i = 0; i < n; i++) {
            int tt ; cin >> tt;
           if(tt <= 0)  dq.push_back(tt);
           else bq.push_back(tt);
        }
        sort(dq.begin(), dq.end());
        sort(bq.begin(), bq.end());
        int mindiff = INT_MAX;
        for (int i = 0; i < (int)dq.size() - 1; i++) {
            mindiff = min(mindiff, abs(dq[i] - dq[i + 1])); 
        }
        int ans = dq.size();
        if(!bq.empty() && bq.front() <= mindiff) ++ans;
        cout << ans << '\n';

    }
}
