// You are given an array a[0, ... , n - 1],
// You will be given queries of the form "l r"
// You need to find the sum from a[l, ... r]

#include<bits/stdc++.h>
using namespace std;
// we store the Segment Tree simply as an array t[] with a size of four times the input size n:
int n;
vector<int> t, v;
void build(int in, int s, int e) {
    // v -> input vector
    // in -> index of current vertex (where the sum will be stored)
    // s, e -> boundaries of the current segment
    if(s == e) {
        // Single element, So no need to divide again
        t[in] = v[s];
    }
    else {
        // First we will make recursive calls on the left child of this vertex and then on the right child of 
        // this vertex and then use both of them to calculate the current sum
        int mid = (s + e) / 2; // Mid-Point from where the current segment will be broken
        build(2 * in, s, mid); // Calculate for left child
        build(2 * in + 1, mid + 1, e); // Calculate for right child
        
        t[in] = t[2 * in] + t[2 * in + 1]; // Using children to calculate the current answer
    }
}
int sum(int in, int s, int e, int ql, int qr) {
    // All same
    // ql, qr -> range of the query
    
    if(ql > qr) {
        return 0; // This case is not possible or in other words, in the segment in which I am currently present,
                  // the original query(ql   qr) and this segment's boundary (s, e) have nothing in common.
    }
    if(s == ql && e == qr) {
        // Totally coinciding
        // Therefore taking all
        return t[in];
    }
    int mid = (s + e) / 2;
    return sum(2 * in, s, mid, ql, min(qr, mid)) + sum(2 * in + 1, mid + 1, e, max(s, mid + 1), qr);
    // First call is on the left child
    // left child boundaries -> [s, mid]
    // But, we have changed the query boundaries => [ql, min(qr, mid)]
    // Why?
    // Consider that I am at index 1 with seg boundaries as -> [1, 6]
    // Suppose my query range is [2, 5]
    // We can see that we have to make calls on both child of index '1'
    // So instead of saying to the first child that "give me the sum of coinciding range of (2, 5) and [1, 3])"
    // It is much better to say that "give me the sum of coinciding range of (2, 3) and [1, 3]" because (2, 5)
    // obviously kind of absurd as we are in range [1, 3] and then also thinking about range (2, 5).
}
void update(int in, int s, int e, int pos, int nval) {
    // All same
    // nval, pos -> Updated value "nval" at index (according to array) "pos"
    if(s == e) {
        t[in] = nval;
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) {
            update(2 * in, s, mid, pos, nval);
        }
        else {
            update(2 * in + 1, mid + 1, e, pos, nval);
        }
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}
int main() {
    // Although, we can store the segment tree in some kind of struct, which will keep the range and other things
    // But, there is an much easy way to do the same thing

    // We create an array of size 4 * n, and we give the nodes present in the segment tree, some kind of index
    // What index?
    // So, we give the root vertex index = 1
    // Then it's left child has index = 2 and right child index = 3
    //
    // Or in other words, the left child gets index 2 * i, and the right child gets the index (2 * i + 1)
    // And same goes for all other nodes
    //
    // In this way, every node in the segment tree gets some particular index and the value of that segment can 
    // be stored at that index
    //
    //            1
    //        2       3
    //     4    5  6     7
    //      ...
    cin >> n; // Number of elements in the array
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    t.assign(4 * n, 0);
    build(v, 1, 0, n - 1);
    cout << sum(1, 0, n - 1, 1, 4) << '\n' << sum(1, 0, n - 1, 0, 2) << endl;
    update(1, 0, n - 1, 0, 0);
    cout << sum(1, 0, n - 1, 0, 1);
    return 0;
}
