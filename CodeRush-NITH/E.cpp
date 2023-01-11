#include <bits/stdc++.h>
// #include<trapv>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
int main() {

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    int lg[n + 1];
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;

    int K = 28;

    int st[K + 1][n + 1], st1[K + 1][n + 1];
 

    std::copy(v.begin(), v.end(), st[0]);
    std::copy(v.begin(), v.end(), st1[0]);
    
    
    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st1[i][j] = max(st1[i - 1][j], st1[i - 1][j + (1 << (i - 1))]);
    
    ll diff = 0;
    
    vector<ll> anss(n);
    
    map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i) mp[v[i]].push_back(i);
    
    for(int i = 0; i < n; ++i) {
        int s = i;
        int e = n - 1;
        if(upper_bound(all(mp[v[i]]), i) != mp[v[i]].end()) {
            e = (*upper_bound(all(mp[v[i]]), i)) - 1;
        }
        
        int ans = 0;
        while(s <= e) {
            int mid = (s + e) >> 1;
            int ij = lg[mid - i + 1];
            int minimum = min(st[ij][i], st[ij][mid - (1 << ij) + 1]);
            if(minimum == v[i]) {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        ll one = (ans - i + 1);
        
        s = 0, e = i;
        
        if(lower_bound(all(mp[v[i]]), i) != mp[v[i]].begin()) {
            s = *(--lower_bound(all(mp[v[i]]), i));
            s++;
        }
        ans = i;
        while(s <= e) {
            int mid = (s + e) >> 1;
            int ij = lg[i - mid + 1];
            int minimum = min(st[ij][mid], st[ij][i - (1 << ij) + 1]);
            if(minimum == v[i]) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        ll two = (i - ans + 1);
        anss[i] -= (one * two);
        
        ans = i;
        s = i, e = n - 1;
        if(upper_bound(all(mp[v[i]]), i) != mp[v[i]].end()) {
            e = (*upper_bound(all(mp[v[i]]), i)) - 1;
        }
        while(s <= e) {
            int mid = (s + e) >> 1;
            int ij = lg[mid - i + 1];
            int minimum = max(st1[ij][i], st1[ij][mid - (1 << ij) + 1]);
            if(minimum == v[i]) {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        one = (ans - i + 1);
        s = 0, e = i;
        if(lower_bound(all(mp[v[i]]), i) != mp[v[i]].begin()) {
            s = *(--lower_bound(all(mp[v[i]]), i));
            s++;
        }
        ans = i;
        while(s <= e) {
            int mid = (s + e) >> 1;
            int ij = lg[i - mid + 1];
            int minimum = max(st1[ij][mid], st1[ij][i - (1 << ij) + 1]);
            if(minimum == v[i]) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        two = (i - ans + 1);
        anss[i] += (one * two);
    }
    diff = 0;
    for(int i = 0; i < n; ++i) {
        cout << anss[i] << endl;
        diff += 1LL * anss[i] * v[i];
    }
    cout << diff;
    return 0;
}