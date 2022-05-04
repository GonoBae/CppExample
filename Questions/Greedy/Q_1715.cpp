#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq; // 작은수부터 자동정렬 -> 기본값은 큰값부터
int main()
{
    int n, num, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        pq.push(num);
    }
    
    while(pq.size() > 1)
    {
        int n1, n2;
        n1 = pq.top(), pq.pop();
        n2 = pq.top(), pq.pop();
        sum += (n1 + n2);
        pq.push(n1 + n2);
    }
    
    cout << sum;
    return 0;
}