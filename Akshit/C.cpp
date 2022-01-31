#include<bits/stdc++.h>
using namespace std;
struct det
{
    string name, roll, address, branch;
    double cgpa;
    det()
    {
        name = roll = address = branch = "";
        cgpa = 0.0;
    }
};
bool cmp(det& a, det& b)
{
    return a.cgpa < b.cgpa;
}
int main()
{
    int n;
    cout << "Enter number of students whose details you want to add\n";
    cin >> n;
    ofstream fin("file1.txt");
    for (int i = 0; i < n; i++) {
        string s;
        cout << "Enter student's name\n";
        cin >> s;
        fin << s << ' ';
        cout << "Enter Roll No.\n";
        cin >> s;
        fin << s << ' ';
        cout << "Enter Address\n";
        cin >> s;
        fin << s << ' ';
        cout << "Enter Branch\n";
        cin >> s;
        fin << s << ' ';
        cout << "Enter CGPA\n";
        cin >> s;
        fin << s << '\n';
    }
    fin.close();
    ifstream fin1("file1.txt");
    vector<det> v;
    int i = 0;
    det temp = det();
    while(!fin1.eof())
    {
        string s;
        fin1 >> s;
        cout << s << endl;
        if(s != "")
        {
            if(i % 5 == 0)
            temp.name = s;
            if(i % 5 == 1)
            temp.roll = s;
            if(i % 5 == 2)
            temp.address = s;
            if(i % 5 == 3)
            temp.branch = s;
            if(i % 5 == 4)
            {
                temp.cgpa = stod(s);
                v.push_back(temp);
                temp = det();
            }
            ++i;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int j = 0; j < v.size(); ++j)
    {
        cout << "For " << j + 1 << "th student\n";
        cout << "Name - Roll - Address - Branch - CGPA\n";
        cout << v[j].name << ' ' << v[j].roll << ' ' << v[j].address << ' ' << v[j].branch << ' ' << v[j].cgpa << endl;
    }
    return 0;
}
