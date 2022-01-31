#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<bool>> vis(1001, vector<bool>(1001, false));
bool isValid(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M || vis[x][y]) return false;
    return true;
}
// So since we want to go to a particular direction, instead of writing code for it
// We can declare two arrays -> dx and dy
// Now we can just iterate over the two arrays and it will change the values of x and y in the same way
// Eg ->
// x + dx[0] = x - 1
// y + dy[0] = y
// This means I will go to "UP"
// Similarly Right, Down, Left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y) // {x, y} are the co-ordinates
{
    vis[x][y] = true;
    
    cout << x << ' ' << y << '\n';

    // Since Common sides are considered to be edges, we will go to these sides one-by-one
    
    /*
    if(isValid(x - 1, y)) // Up
    dfs(x - 1, y);
    
    if(isValid(x, y + 1)) // Right
    dfs(x, y + 1);

    if(isValid(x + 1, y)) // Down
    dfs(x + 1, y);

    if(isValid(x, y - 1)) // Left
    dfs(x, y - 1);
    */
    
    for(int i = 0; i < 4; ++i) // { {-1, 0}, {0, 1}, {1, 0}, {0, -1} } => Up, Right, Down, Left
    {
        if(isValid(x + dx[i], y + dy[i]))
        dfs(x + dx[i], y + dy[i]);
    }
}
int main()
{
    cin >> N >> M;
    dfs(1, 1);
    return 0;
}
