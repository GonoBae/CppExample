#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> V;
vector<int> VB;
priority_queue<int> PQ;

int main()
{
    int N, K;
    int m, v, b;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> m >> v;
        V.push_back(make_pair(m, v));
    }
    for (int i = 0; i < K; i++)
    {
        cin >> b;
        VB.push_back(b);
    }
    sort(V.begin(), V.end());
    sort(VB.begin(), VB.end());

    long long result = 0;
    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        while (idx < N && V[idx].first <= VB[i])
        {
            PQ.push(V[idx++].second);
        }
        if (!PQ.empty())
        {
            result += PQ.top();
            PQ.pop();
        }
    }

    cout << result;
    return 0;
}