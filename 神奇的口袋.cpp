
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。

输入描述:
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。


输出描述:
输出不同的选择物品的方式的数目。
示例1
输入
3
20
20
20
输出
3

#include <iostream>
using namespace std;

int sum = 0;
void func(int* a, int n, int s, int j)
{
    if (s == 0)
        sum++;
    else if (s < 0)
        return;
    else
    {
        for (int i = j; i < n; i++)
        {
            func(a, n, s - a[i], i+1);
        }
    }
}

int main()
{
    int n = 0;
    int num = 40;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    func(a, n, num, 0);
    cout << sum;
    return 0;
}
