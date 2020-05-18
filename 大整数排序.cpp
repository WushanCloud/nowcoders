题目描述
对N个长度最长可达到1000的数进行排序。
输入描述:
输入第一行为一个整数N，(1<=N<=100)。
接下来的N行每行有一个数，数的长度范围为1<=len<=1000。
每个数都是一个正数，并且保证不包含前缀零。
输出描述:
可能有多组测试数据，对于每组数据，将给出的N个数从小到大进行排序，输出排序后的结果，每个数占一行。
示例1
输入
复制
3
11111111111111111111111111111
2222222222222222222222222222222222
33333333

输出
复制
33333333
11111111111111111111111111111
2222222222222222222222222222222222

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct myClass
{
    bool operator()(string a, string b)
    {
        if (a.size() > b.size())
            return false;
        else if (a.size() < b.size())
            return true;
        int i = 0;
        while (i < a.size())
        {
            if (a[i] > b[i])
                return false;
            else if (a[i] < b[i])
                return true;
            else
                i++;
        }
        return true;
    }
}issmall;


int main()
{
    int N = 0;
    while (cin >> N)
    {
        //输入
        vector<string> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), issmall);

        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}

