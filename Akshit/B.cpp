#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of user name to be entered\n";
    cin >> n;
    fstream fout;
    fout.open("file1.txt", ios :: out);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        fout << s << ' ';
    } // Written into file1.txt
    fout.close();
    fout.open("file1.txt", ios :: in);
    vector<string> v;
    while(!fout.eof())
    {
        string s;
        fout >> s;
        if(s != "")
        v.push_back(s);
    }
    sort(v.begin(), v.end()); // Sorted Alphabetically
    fout.close();
    fstream fout2;
    fout2.open("file2.txt", ios :: out | ios :: trunc);
    for (int i = 0; i < v.size(); i++) {
        fout2 << v[i] << ' ';
    }
    fout2.close();
    return 0;
}
