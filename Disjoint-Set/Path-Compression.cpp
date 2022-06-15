/*
 *
 Suppose, one of my disjoint set is ->

    (Parent is 1) 1 <- 2 <- 3 <- 4 <- 5 <- 6 <- 7 <- 8

If I apply the find function on node 8, you can see that it has a time complexity of O(N) to reach to the parent
node. What I can do is that, I can apply Path Compression which means

Since parent of 3 is 2, and parent of 2 is 1, therefore, par[3] = 1 (So that I don't have to get traversed)
Since parent of 4 is 3 and parent of 3 is 1, therefore, par[4] = 1
....

Psuedo Code:

find(a) {
    vector<int> v;
    while(par[a] > 0) {
        v.push_back(a); // Not have reached the parent
        a = par[a];
    }
    // Now, a is parent of the disjoint set
    for(int i = 0; i < sz(v); ++i) {
        par[v[i]] = a;
    }
    return a;
}
