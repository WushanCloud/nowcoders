链接：https://www.nowcoder.com/questionTerminal/58e7779c9f4e413cb80792d33ba6acaf
来源：牛客网

如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二

十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入描述:
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]]区间内的整数，Sickle是[0, 
17)区间内的整数，Knut是[0, 29)区间内的整数。


输出描述:
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
示例1
输入
10.16.27 14.1.28
输出
3.2.1


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string p, a;
    cin >> p >> a;
    vector<int> P(3, 0), A(3, 0);
    p += '.'; a += '.';
    for (int i = 0; i < 3; i++)
    {
        P[i] = stoi(p.substr(0, p.find(".")));
        A[i] = stoi(a.substr(0, a.find(".")));
        p = p.substr(p.find(".") + 1, p.size());
        a = a.substr(a.find(".") + 1, a.size());
    }
    int m = 0;
    m = (A[0] - P[0]) * 17 * 29 + (A[1] - P[1]) * 29 + A[2] - P[2];
    if (m < 0)
    {
        cout << "-";
        m = -m;
    }
    cout << m / 17 / 29<< ".";
    m %= 29 * 17;
    cout << m / 29 << ".";
    m %= 29;
    cout << m;
    return 0;
}
