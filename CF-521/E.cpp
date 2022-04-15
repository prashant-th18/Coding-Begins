#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200001;
int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> occ;
    for(int i = 0; i < n; ++i) cin >> v[i], occ[v[i]]++;
    vector<int> ans;
    for(auto val : occ)
    {
        ans.push_back(val.second);
    }
    int here = INT_MIN, s = ans.size();
    sort(ans.begin(), ans.end());
    int maxx = *max_element(begin(ans), end(ans));
    auto binSearch = [&](int index, int temp) -> int {
        int a = s;
        int si = index + 1, ei = s - 1;
        while(si <= ei)
        {
            int mid = (si + ei) >> 1;
            if(ans[mid] >= temp)
            {
                a = mid; ei = mid - 1;
            }
            else si = mid + 1;
        }
        return a;
    };
    for(int st = 1; st <= maxx; ++st)
    {
        int add = 0;
        int temp = st;
        auto it = lower_bound(begin(ans), end(ans), temp) - begin(ans);
        while(it != s) {
            add += temp;
            temp *= 2;
            it = binSearch(it, temp);
            if(it == s) break;
        }
        here = max(here, add);
    }
    cout << here;
    return 0;
}
