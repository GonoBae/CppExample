#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> V[100001];
int C[100001];
int N, M, R, cnt = 1;

void dfs(int x)
{
    C[x] = cnt++;
    for(int i = 0; i < V[x].size(); i++)
    {
        int y = V[x][i];
        if(C[y]) continue;
        dfs(y);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> R;
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    // 내림차순으로 정렬한다.
    for(int i = 1; i <= N; i++)
    {
        sort(V[i].begin(), V[i].end(), greater<>());
    }

    dfs(R);
    
    for(int i = 1; i <= N; i++)
    {
        cout << C[i] << '\n';
    }
    return 0;
}