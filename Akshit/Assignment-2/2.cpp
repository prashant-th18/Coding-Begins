#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
int main(){
    int num;
    cout<<"Enter number of users"<<endl;
    cin>>num;
    string* unsorted_name=new string[num];   //dynamically allocated memory
    cout<<"Enter names of users"<<endl;
    for(int i = 0;i<num; i++){
        cin>>unsorted_name[i];
    }
    ofstream file1{"unsorted_names.txt"};
    for(int i{0};i<num;i++){
        file1<<unsorted_name[i]<<endl;
    }
    string* sorted_name=new string[num];
    ifstream file2{"unsorted_names.txt"};    
    int i = 0;
    while(!file2.eof()){
        file2>>sorted_name[i];
        i++;
    }
    string min,temp;
    for(int i{0};i<num-1;i++){
       min=sorted_name[i];
       for(int j = i + 1;j<num;j++)
         {
              if(min>sorted_name[j])
              {
                min=sorted_name[j];
                sorted_name[j]=sorted_name[i];
                sorted_name[i]=min;
              }
         }
    }
    ofstream file3{"sorted_names.txt"};
    for(int i = 0;i<num;i++){
        file3<<sorted_name[i]<<endl;
    }
    file1.close();
    file2.close();
    file3.close();
    // All opened files closed
    return 0;
}