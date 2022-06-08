#include<bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    int n = 2 * 100000;
    cout << 1 << endl << n << ' ' << 1000 << endl;
    cout << 123456789;
    for(int i = 1; i < n; ++i) cout << ' ' << rand() % 123456789;
    cout << endl;
}

