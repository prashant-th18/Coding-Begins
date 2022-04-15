#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(count(begin(v), end(v), v[0]) == n) cout << 0;
    else {
        int mini = N + 1;
        for(int i = 1; i <= N; ++i) {
            // make every element == i
            set<int> st;
            for(int j = 0; j < n; ++j) {
                int diff = abs(v[j] - i);
                if(diff != 0) st.insert(diff);
            }
            if(st.size() == 1)
            {
                mini = min(mini, *st.begin());
            }
        }
        if(mini == N + 1) mini = -1;
        cout << mini;
    }
    return 0;
}
