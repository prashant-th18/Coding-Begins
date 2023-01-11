#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    int steps = 0;
    while(m>n){
        steps++;
        if(m&1)
            m/=2;
        else m++;
    }
    
    steps += max(0LL,n-m);
    cout<<steps<<'\n';
    
    return 0;
}
