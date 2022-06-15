/*
pseudo-code

Assuming that a parent array is already and initialised

find(n):
    while(n != parent[n]) {
        n = parent[n];
    }
    return n; // The main parent of whole set


Recursive:
find(n):
    if(n == parent[n]) return n;
    return find(parent[n]);

*/
