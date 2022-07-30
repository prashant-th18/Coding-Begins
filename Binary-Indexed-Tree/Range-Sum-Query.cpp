/*
 * Q1. Array - N <= 10^5
 *     Queries - Q <= 10^5
 *
 * Q -> Type1: Update ith index with "x"
 *      Type2: Sum from "l" to "r"
 */
#include"bits/stdc++.h"
using namespace std;
int n;
vector<int> v, bit;
void update(int in, int x) {
    for(; in <= n; in += (in & (-in))) {
        bit[in] += x;
    }
}
int sum(int in) {
    int s = 0;
    for(; in > 0; in -= (in & (-in))) {
        s += bit[in];
    }
    return s;
}
int main() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bit.assign(n + 1, 0); // 1 - Based
    for(int i = 1; i <= n; ++i) {
        update(i, v[i - 1]);
    }
    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int i, x; cin >> i >> x;
            // We want to change value at index "i" to "x"
            // So, we can update the added values to the indices of the bit array
            // How?
            // Initially, the value of index "i" used to make bit arrays was: v[i - 1]
            // What is the new value at index "i" -> x
            // What is the change -> x - v[i - 1]
            // So, we will add this change to all the appropriate bit indices
            update(i, x - v[i - 1]);
            v[i - 1] = x;
        }
        else {
            int l, r; cin >> l >> r;
            cout << sum(r) - sum(l - 1) << '\n';
        }
    }
    return 0;
}
