
输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。

输入描述:
输入有多组数据。
每组一行，输入n。


输出描述:
输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数(素数之间用空格隔开，最后一个素数后面没有空格)，如果没有则输出-1。
示例1
输入
100
输出
11 31 41 61 71

#include <iostream>
#include <vector>
using namespace std;

bool find(int m)
{
    for(int i = 3; i < m/3; i += 2)
    {
        if (!(m % i))
            return false;
    }
    return true;
}

int main()
{
    int n = 0;
    cin >> n;
    if (n < 11)
    {
        cout << -1;
        return 0;
    }
        
    vector <int> arr;
    for (int i = 11; i < n; i += 10)
    {
        if (find(i))
            arr.push_back(i);
    }
    for (int i = 0; i < arr.size()-1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr.back();
    return 0;
}
