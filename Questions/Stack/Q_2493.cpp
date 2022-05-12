#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    stack<pair<int, int>> S;
    S.push(make_pair(0, 100000000));
    for(int i = 1; i <= N; i++)
    {
        int t;
        cin >> t;
        while(S.top().second < t) S.pop();
        cout << S.top().first << ' ';
        S.push(make_pair(i, t));
    }
    return 0;
}