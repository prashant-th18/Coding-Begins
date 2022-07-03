// Counting the number of zeros, searching for the k-th zero
//
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = (v[s] == 0);
    }
    else {
        int mid = (s + e) >> 1;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = (nval == 0);
    }
    else {
        int mid = (s + e) >> 1;
        if(pos <= mid) {
            update(2 * in, s, mid, pos, nval);
        }
        else {
            update(2 * in + 1, mid + 1, e, pos, nval);
        }
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}
int countZeros(int in, int s, int e, int qs, int qe) {
    if(qs > qe) {
        return 0;
    }
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) / 2;
    return countZeros(2 * in, s, mid, qs, min(qe, mid)) + countZeros(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe);
}
int kthZero(int in, int s, int e, int k) {
    if(t[in] < k) {
        // Not present
        return -1;
    }
    if(s == e) {
        // This is the index which is kth zero(1 - based)
        return s;
    }
    int mid = (s + e) / 2;
    if(t[2 * in] >= k) {
        return kthZero(2 * in, s, mid, k);
    }
    else {
        // If we are going to the right subtree, we subtract k from t[2 * in], because, in the right subtree (2 * in + 1), again, all the zeros 
        // are indexed 1 - based (from 1 to t[2 * in + 1])
        // So, we have to remove all the zeros of the left subtree (t[2 * in])
        return kthZero(2 * in + 1, mid + 1, e, k - t[2 * in]);
    }
}
int main() {
    cin >> n; // Number of elements
    v.assign(n, 0);
    t.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    cout << countZeros(1, 0, n - 1, 0, n - 1) << endl;
    update(1, 0, n - 1, 2, 0);
    cout << kthZero(1, 0, n - 1, 2);
    return 0;
}
