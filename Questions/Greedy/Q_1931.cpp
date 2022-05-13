#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second < b.second) return true;
    else if(a.second > b.second) return false;
    if(a.first < b.first) return true;
    else return false;
}
int main()
{
    int N, time = 0, s = 0;
    vector<pair<int, int>> V;
    cin >> N;
    while(N--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        V.push_back(make_pair(t1, t2));
    }
    sort(V.begin(), V.end(), compare);
    for(int i = 0; i < V.size(); i++)
    {
        if(time <= V[i].first)
        {
            time = V[i].second;
            s++;
        }
    }
    cout << s;
    return 0;
}