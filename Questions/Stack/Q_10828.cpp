#include <iostream>
#include <cstring>
using namespace std;

int arr[10001], cnt = 0;
void push(int x)
{
    arr[cnt++] = x;
}
int pop()
{
    if(cnt == 0) return -1;
    return arr[--cnt]; 
}
int top()
{
    if(cnt == 0) return -1;
    return arr[cnt - 1];
}
int size()
{
    return cnt;
}
int empty()
{
    if(cnt == 0) return 1;
    return 0;
}
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        char cmd[30];
        cin >> cmd;
        if(strcmp(cmd, "push") == 0)
        {
            int t;
            cin >> t;
            push(t);
        }
        else if(strcmp(cmd, "pop") == 0)
            cout << pop() << endl;
        else if(strcmp(cmd, "top") == 0)
            cout << top() << endl;
        else if(strcmp(cmd, "empty") == 0)
            cout << empty() << endl;
        else if(strcmp(cmd, "size") == 0)
            cout << size() << endl;
    }
    return 0;
}