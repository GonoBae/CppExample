#include <iostream>
#include <queue>
using namespace std;

int M, N, s = 0; // 가로 , 세로
int map[1001][1001];
int dx[4] = {-1, 1, 0, 0}; // 좌 우
int dy[4] = {0, 0, -1, 1}; // 상 하
queue<pair<int, int>> Q;
void bfs()
{
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(map[nx][ny] != 0) continue;
            map[nx][ny] = map[x][y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    cin >> M >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
            {
                Q.push(make_pair(i, j));
            }
        }
    }

    bfs();

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(map[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            if(s < map[i][j])
            {
                s = map[i][j];
            }
        }
    }
    cout << s - 1;
    return 0;
}