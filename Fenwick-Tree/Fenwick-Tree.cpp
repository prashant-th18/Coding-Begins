#include"bits/stdc++.h"
using namespace std;
struct FenwickTree {
    // 1 - Based
    vector<int> bit; // Binary Indexed Tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            add(i, a[i]);
        }
    }

    void add(int in, int delta) {
        // This says -> Kis index(original array ke) pr kitna delta add krna hai
        // So, hm un sb "j" pr jaate hai jo -> g(j) <= i <= j, ye follow krte hai
        for(; in < n; in = in | (in + 1)) {
            bit[in] += delta;
        }
    }

    int sum(int r) {
        int res = 0;
        while(r >= 0) {
            res += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

struct FenwickTreeMin {

    // It is obvious that there is no easy way of finding minimum of range [l, r] using Fenwick tree, as 
    // Fenwick tree can only answer queries of type [0, r]. . Additionally, each time a value is update'd, 
    // the new value has to be smaller than the current value.

    vector<int> bit; // Binary Indexed Tree
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()) {
        for(int i = 0; i < n; ++i) {
            update(i, a[i]);
        }
    }

    void update(int in, int val) {
        while(in < n) {
            bit[in] = min(bit[in], val);
            in = in | (in + 1);
        }
    }

    int getMin(int r) {
        int res = INF;
        while(r >= 0) {
            res = min(res, bit[r]);
            r = (r & (r + 1)) - 1;
        }
        return res;
    }
};

struct FenwickTree2D {
    // Using this, we can apply operations on X & Y axis.
    vector<vector<int>> bit;
    int n, m;

    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n, vector<int>(m, 0));
    }

    FenwickTree2D(vector<vector<int>> a) : FenwickTree2D(a.size(), a[0].size()) {
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                add(i, j, a[i][j]);
            }
        }
    }

    void add(int x, int y, int delta) {
        for(int i = x; i < n; i = i | (i + 1)) {
            for(int j = y; j < m; j = j | (j + 1)) {
                bit[i][j] += delta;
            }
        }
    }

    int sum(int x, int y) {
        // Calculate sum from (0, 0) to (x, y)
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for(int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                res += bit[i][j];
            }
        }
        return res;
    }
}
int main() {
    FenwickTree t = FenwickTree(5);
    t.add(1, 3); t.add(3, 2);
    cout << t.sum(3) << endl << t.sum(2, 3) << endl;
    vector<int> v = {1, 2, 4, 3, 1};
    FenwickTreeMin a = FenwickTreeMin(v);
    cout << a.getMin(3) << endl;
    a.update(1, 100);
    cout << a.getMin(4) << endl;
    return 0;
}
