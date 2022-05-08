#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, zero = 0, result = 0;
    vector<int> VP;
    vector<int> VN;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if(num > 1) VP.push_back(num);
        else if(num == 0) zero++;
        else if(num == 1) result++;
        else VN.push_back(num);
    }
    sort(VP.begin(), VP.end(), greater<int>());
    sort(VN.begin(), VN.end(), less<int>());
    for(int i = 0; i < VP.size(); i+=2)
    {
        if(i + 1 == VP.size())
        {
            result += VP[i];
            break;
        }
        result += VP[i] * VP[i + 1];
    }
    for(int i = 0; i < VN.size(); i+=2)
    {
        if(i + 1 == VN.size())
        {
            if(zero == 0) 
            {
                result += VN[i];
                break;
            }
            break;
        }
        result += VN[i] * VN[i + 1];
    }
    cout << result;
    return 0;
}