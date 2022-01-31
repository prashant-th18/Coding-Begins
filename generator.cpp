#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q = 5 * 1e5;
    cout << q << endl;
    for(int i = 0; i < q / 2; ++i)
    {
        cout << 1 << ' ' << i + 1 << endl;
    }
    for(int i = 0; i < q / 2; ++i)
    {
        cout << 2 << ' ' << i + 1 << ' ' << i + 2 << endl;
    }
    return 0;
}
