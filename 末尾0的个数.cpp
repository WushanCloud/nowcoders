
输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2

输入描述:
输入为一行，n(1 ≤ n ≤ 1000)


输出描述:
输出一个整数,即题目所求
示例1
输入
10
输出
2

#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int count = 0;
    while (n /= 5)
    {
        count += n;
    }
    cout << count;
    return 0;
}

