

给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

输入描述:
每个输入包含1个测试用例，即一个不超过1000位的正整数N。


输出描述:
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。
示例1
输入
100311
输出
0:2<br/>1:3<br/>3:1

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int sum[10] = {0};
    for (int i = 0; i < n.size(); i++)
    {
        sum[n[i]-'0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (sum[i])
        {
            cout << i << ":" << sum[i] << endl;
        }
    }
    return 0;
}
