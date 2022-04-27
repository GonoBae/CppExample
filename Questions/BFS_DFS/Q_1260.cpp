#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> V[10001];
bool c[10001];
bool d[10001];
void bfs(int x)
{
    queue<int> Q;
    Q.push(x);
    d[x] = true;
    while(!Q.empty())
    {
        int y = Q.front();
        Q.pop();
        cout << y << ' ';
        for(int i = 0; i < V[y].size(); i++)
        {
            int z = V[y][i];
            if(!d[z])
            {
                Q.push(z);
                d[z] = true;
            }
        }
    }
}

void dfs(int x)
{
    if(c[x]) return;
    c[x] = true;
    cout << x << ' ';
    for(int i = 0; i < V[x].size(); i++)
    {
        int y = V[x][i];
        dfs(y);
    }
}

int main()
{
    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }

    for(int i = 0; i < m; i++)
    {
        sort(V[i].begin(), V[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
    
    return 0;
}