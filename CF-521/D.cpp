#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int main() {
    int n, k; cin >> n >> k;
    vector<int> occ(N, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        occ[t]++;
    }
    vector<int> ans, myans;
    auto can = [&](int cnt) -> bool {
        ans.clear();
        for(int i = 1; i < N; ++i)
        {
            int need = min(occ[i] / cnt, k - (int)ans.size());
            for(int j = 0; j < need; ++j)
            {
                ans.push_back(i);
            }
        }
        return ans.size() == k;
    };
    {
        int s = 1, e = n + 1;
        while(s <= e)
        {
            int mid = (s + e) >> 1;
            if(can(mid))
            {
                myans = ans;
                s = mid + 1;        
            }
            else e = mid - 1;
        }
    }
    for(auto val : myans) cout << val << ' ';
    return 0;
}
