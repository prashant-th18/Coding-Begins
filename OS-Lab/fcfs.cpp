#include<bits/stdc++.h>
using namespace std;
int main(){
int n,head;
cin >> n >> head;
vector<int>ref(n);
for(int &a:ref){
cin >> a;
}
int seekcount=0;
for(int i=0;i<ref.size();i++){
seekcount+=abs(ref[i]-head);
head=ref[i];
}
cout << seekcount << "\n";
}