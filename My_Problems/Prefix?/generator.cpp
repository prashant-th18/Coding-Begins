#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 200000);
    string a = string(n, '.');
    for(int i = 0; i < n; ++i)
    {
        char ch = ('a' + ((rnd.next(1, 100000) % 26)));
        a[i] = ch;
    }
    string b = a.substr(0, rnd.next(1, max(1, n / 3)));
    if(rnd.next(1, 10) % 2 == 0) shuffle(b.begin(), b.end());
    cout << b << endl << a << endl;
}
