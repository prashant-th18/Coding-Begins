#include"bits/stdc++.h"
#include "testlib.h"
using namespace std;

void form(string& s) {
    if(s.size() == 1) s = "0" + s;
}
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int hour = rnd.next(0, 23);
    string h = to_string(hour);
    int minutes = rnd.next(0, 59);
    string m = to_string(minutes);
    form(h); form(m);
    cout << h << ":" << m << endl;
    return 0;
}
