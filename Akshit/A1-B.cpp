#include<bits/stdc++.h>
using namespace std;
void bubble_Sort(vector<int> v)
{
    int comp = 0;
    int n = v.size();
    for(int i = 0; i < n - 1; ++i)
    {
        bool flag = false;
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(v[j] > v[j + 1])
            {
                flag = true;
                swap(v[j], v[j + 1]);
            }
            ++comp;
        }
        if(!flag)
        {
            break;
        }
    }
    cout << "Comparisons done -> " << comp << endl;
    cout << "After Bubble Sort, Vector is \n";
    for(int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
    cout << endl;
}
void selection_Sort(vector<int> v)
{
    int comp = 0;
    int n = v.size();
    for(int i = 0; i < n - 1; ++i)
    {
        int index = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(v[j] < v[index])
            {
                index = j;
            }
            ++comp;
        }
        swap(v[i], v[index]);
    }
    cout << "Comparisons done -> " << comp << endl;
    cout << "After Selection Sort, Vector is \n";
    for(int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
    cout << endl;
}
int main()
{
    int n; cout << "Enter number of elements\n"; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter " << (i + 1) << "th element\n";
        cin >> v[i];
    }
    cout << "Before Sorting\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    bubble_Sort(v);
    selection_Sort(v);
    return 0;
}
