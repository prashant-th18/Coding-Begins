#include"bits/stdc++.h"
#include "testlib.h"
using namespace std;

int main() {
    int n = 100000;
    string res = string(n, '.');
    res[0] = rnd.next(1, 9) + '0';
    for(int i = 1; i < n; ++i) {
        res[i] = rnd.next(0, 9) + '0';
    }
    cout << res << endl;
    return 0;
}

