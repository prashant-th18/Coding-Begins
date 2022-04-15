#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, B, A; cin >> n >> B >> A;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int b = B, a = A, i;
    for(i = 0; i < n && (!(b == 0 && a == 0)); ++i) {
        if(v[i] == 1) {
            if(b != 0) {
                if(a != A) ++a, --b;
                else {
                    --a;
                }
            }
            else {
                --a;
            }
        }
        else {
            if(a != 0) --a;
            else --b;
        }
    }
    cout << i;
    return 0;
}
