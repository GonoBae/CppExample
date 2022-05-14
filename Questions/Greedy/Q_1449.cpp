// 좌우 0.5 만큼씩 여유를 두어야 한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> V;
    int N, L, s = 1;
    int first = 0;
    cin >> N >> L;
    while(N--)
    {
        int t;
        cin >> t;
        V.push_back(t);
    }
    sort(V.begin(), V.end());
    first = V[0];
    for(int i = 1; i < V.size(); i++)
    {
        if(V[i] - first + 1 > L)
        {
            s++;
            first = V[i];
        }
    }
    cout << s;
    return 0;
}