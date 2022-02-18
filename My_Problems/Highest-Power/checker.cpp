#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

inline int readAndCheckAnswer(InStream& in) {
    return in.readInt();
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int n = inf.readInt();
    if(readAndCheckAnswer(ouf) == readAndCheckAnswer(ans))
    {
        quitf(_ok, "Passed!");
    }
    else
    {
        quitf(_wa, "Wrong Answer :sad:");
    }
    
}
