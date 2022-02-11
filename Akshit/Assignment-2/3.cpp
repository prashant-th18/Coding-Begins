#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<limits>
using namespace std;
struct student {
    string name,city,roll_no,branch;
    float cgpa;
};
int main(){
    int number;
    cout<<"Enter the number of students"<<endl;
    cin>>number;
    student* data=new student[number];          //dynamically allocated
    cout<<"Enter the details of students"<<endl;
    for(int i = 0;i<number;i++){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //for ignoring the newline character
        cout<<"Enter name of student "<<i+1<<endl;
        getline(cin >> ws,data[i].name);
        cout<<"Enter roll number of student "<<i+1<<endl;
        getline(cin >> ws,data[i].roll_no);
        cout<<"Enter branch of student "<<i+1<<endl;
        getline(cin >> ws,data[i].branch);
        cout<<"Enter city of student "<<i+1<<endl;
        getline(cin  >> ws,data[i].city);
        cout<<"Enter cgpa of student "<<i+1<<endl;
        cin>>data[i].cgpa;
    }
    ofstream file{"student_details.txt"};
    file<<setw(25)<<left<<"Name"<<"Roll No\t"<<setw(10)<<"Branch\t"<<setw(55)<<"City"<<setw(5)<<right<<"CGPA"<<endl;
    for(int i = 0;i<number;i++){
        file<<setw(25)<<left<<data[i].name<<data[i].roll_no<<"\t"<<setw(10)<<data[i].branch<<setw(55)<<data[i].city<<setw(5)<<right<<data[i].cgpa<<endl;   //using setw() and left() right() for formatted output in file
    }
    file.close();
    ifstream file2{"student_details.txt"};
    string heading;
    getline(file2,heading);
    int i{0};
    student *sorted_data=new student[number];
    while(!file2.eof() && i < number){
    file2>>sorted_data[i].name>>sorted_data[i].roll_no>>sorted_data[i].branch>>sorted_data[i].city>>sorted_data[i].cgpa;
    i++;
    }
    float min;
    student tempp;
    for(int i{0};i<number-1;i++){
       min=sorted_data[i].cgpa;
       tempp=sorted_data[i];
       for(int j = i + 1;j<number;j++)
         {
              if(min>sorted_data[j].cgpa)
              {
                tempp=sorted_data[j];
                min=sorted_data[j].cgpa;
                sorted_data[j]=sorted_data[i];
                sorted_data[i]=tempp;
              }
         }
    }
    cout<<"List of students in ascending order of cgpa : "<<endl;
    cout<<setw(25)<<left<<"Name"<<"Roll No\t"<<setw(10)<<"Branch\t"<<setw(55)<<"City"<<setw(5)<<right<<"CGPA"<<endl;
    for(int i{0};i<number;i++){
        cout<<setw(25)<<left<<sorted_data[i].name<<sorted_data[i].roll_no<<"\t"<<setw(10)<<sorted_data[i].branch<<setw(55)<<sorted_data[i].city<<setw(5)<<right<<sorted_data[i].cgpa<<endl;
    }
    return 0;
}