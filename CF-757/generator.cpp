#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    cout << n << ' ' << 10 << endl;
    int tt = (1LL << 30) - 1;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ' ' << (i + 1) << ' ' << (tt--) << endl;
    }
    return 0;
}
