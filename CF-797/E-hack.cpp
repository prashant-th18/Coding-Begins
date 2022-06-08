#include<bits/stdc++.h>
using namespace std;
static std::random_device rd; // random device engine, usually based on /dev/random on UNIX-like systems
// initialize Mersennes' twister using rd to generate the seed
static std::mt19937 rng{rd()};

int dice()
{
    static std::uniform_int_distribution<int> uid(1, 1000000000); // random dice
    return uid(rng); // use rng as a generator
}
int main() {
    int n = 2 * 100000;
    fstream fout;
    fout.open("inp", ios :: out | ios :: trunc);
    fout << 1 << endl << n << ' ' << 1000 << endl;
    fout << dice();
    for(int i = 1; i < n; ++i) fout << ' ' << dice();
    fout << endl;
}
