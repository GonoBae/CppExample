#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int C[1000001];
//vector<int> C(100001, 0);
vector<int> V[100001];
int N, M, R, cnt = 1;
void dfs(int x)
{
    if(C[x]) return;
     C[x] = cnt++;
    // for(auto &nxt : V[x])
    // {
    //     if(C[nxt] != 0) continue;
    //     dfs(nxt);
    // }
    
    for(int i = 0; i < V[x].size(); i++)
    {
        int y = V[x][i];
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
        int t1, t2;
        cin >> t1 >> t2;
        V[t1].push_back(t2);
        V[t2].push_back(t1);
    }

    for(int i = 1; i <= N; i++)
    {
        sort(V[i].begin(), V[i].end());
    }
    dfs(R);
    for(int i = 1; i <= N; i++)
        cout << C[i] << '\n';
    return 0;
}