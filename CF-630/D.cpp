#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k; cin >> k;
    int power = 1;
    int lim = 300000;
    while(((1 << power) - 1) <= lim)
    {
        ++power;
    }
    --power;
    int num1 = (1 << power) - 1;
    int num2 = (1 << (power - 1));
    int num3 = num2 - 1;
    vector<vector<int>> v(3, vector<int>(3, 0));
    v[0][0] = v[2][0] = v[2][1] = num1;
    v[1][0] = num2;
    v[0][1] = v[1][1] = v[2][2] = num3;
    v[0][2] = v[1][2] = num3 - k;
    cout << 3 << ' ' << 3 << '\n';
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
