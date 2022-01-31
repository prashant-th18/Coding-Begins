#include <bits/stdc++.h>
using namespace std;
int binary_Search(vector<int> v, int elem)
{
    sort(v.begin(), v.end());
    int s = 0, e = v.size() - 1;
    int comp = 0, ans = -1;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        if(v[mid] < elem)
        {
            s = mid + 1;
        }
        else if(v[mid] == elem)
        {
            ans = mid; break;
        }
        else e = mid - 1;
        ++comp;
    }
    cout << "Element is present at " << ans + 1 << "th index\n";
    return comp;
}
int linear_Search(vector<int> v, int elem)
{
    int comp = 1;
    for(int i = 0; i < v.size(); ++i, ++comp)
    {
        if(v[i] == elem)
        {
            cout << "Element is present at " << (i + 1) << "th index\n";
            return comp;
        }
    }
}
int main()
{
    int n;
    cout << "Enter size of the vector\n";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter " << (i + 1) << "th element\n";
        cin >> v[i];
    }
    int elem;
    cout << "Enter element to be found in the vector\n";
    cin >> elem;
    int take_bin = binary_Search(v, elem);
    int take_lin = linear_Search(v, elem);
    cout << "Number of comparisons done by Binary Search -> " << take_bin << endl;
    cout << "Number of comparisons done by Linear Search -> " << take_lin << endl;
    return 0;
}
