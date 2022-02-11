#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct customer {
    int sr_no,age;
    string name;
};
int main(){
    int num;
    cout<<"Enter number of users to read from txt file"<<endl;
    cin>>num;
    customer* mydata = new customer[num];  //dynamic memory allocation
    ifstream file{"customer.txt"};
     if(!file){
        cout<<"Error Opening customer.txt File"<<'\n';
        return 0;
    }
    int i = 0;
    string heading;
    getline(file,heading);
    while(!file.eof() && i < num){
    file>>mydata[i].sr_no>>mydata[i].name>>mydata[i].age;
    i++;
    }
    cout<<"Customers whose age is more than 20 are : "<<endl;
    for(int i{0};i<num;i++){
            if(mydata[i].age > 20){
            cout<<mydata[i].name<<"   "<<mydata[i].age<<"\n";
        }
    }
    file.close();
    return 0;
}