链接：https://www.nowcoder.com/questionTerminal/ac61207721a34b74b06597fe6eb67c52
来源：牛客网

给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。


输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1
输入
7 2
输出
111

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char tonum(int n)
{
    if (n >= 0 && n <= 9)
    {
        return n + '0';
    }
    return (n-10) + 'A';
}

int main()
{
    int M, N;
    while (cin >> M >> N)
    {
        string s;
        string tmp = "";
        if (M < 0)
        {
            M = 0 - M;
            tmp = "-";
        }
        if (M == 0)
            s += '0';
        else
        while (M)
        {
            s += tonum(M % N);
            M /= N;
        }
        s += tmp;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
