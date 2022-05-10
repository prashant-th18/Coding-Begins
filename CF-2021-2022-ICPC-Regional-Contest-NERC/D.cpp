#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        vector<bool> vis(26, true);
        int i = a.size() - 1, j = b.size() - 1;
        bool flag = true;
        while(i >= 0 && j >= 0) {
            if(a[i] != b[j]) {
                vis[a[i] - 65] = false;
            }
            else {
                if(!vis[b[j] - 65]) {
                    flag = false; break;
                }
                --j;
            }
            --i;
        }
        if(j >= 0) flag = false;
        cout << ((flag) ? ("Yes") : ("No")) << '\n';
    }
    return 0;
}
