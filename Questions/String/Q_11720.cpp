#include <iostream>
using namespace std;
int arr[101];
int main()
{
    int N, sum = 0;
    string str;
    cin >> N;
    cin >> str;
    for(int i = 0; i < N; i++)
    {
        arr[i] = str[i] - '0';
        sum += arr[i];
    }
    cout << sum;
    return 0;
}