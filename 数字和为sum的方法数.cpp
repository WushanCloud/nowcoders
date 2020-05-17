题目描述
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
输入描述:
输入为两行:
 第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)
 第二行为n个正整数A[i](32位整数)，以空格隔开。
输出描述:
输出所求的方案数
示例1
输入
复制
5 15 5 5 10 2 3
输出
复制
4

#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n, sum;
    cin >> n >> sum;
    vector<long> tmp(sum + 1, 0), input(n + 1, 0);
    tmp[0] = 1, input[0] = 0;
    vector<vector<long> >dp(n + 1, tmp);

    for (int i = 1; i <= n; i++)
        cin >> input[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - input[i] >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - input[i]]; 
            else 
                dp[i][j] = dp[i - 1][j]; //否则直接继承该列上一行值
        }
    }
    cout << dp[n][sum] << endl;  //输出最后一个
    return 0;
}
