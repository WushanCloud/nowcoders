题目描述
守形数是这样一种整数，它的平方的低位部分等于它本身。 比如25的平方是625，低位部分是25，因此25是一个守形数。 编一个程序，判断N是否为守形数。
输入描述:
输入包括1个整数N，2<=N<100。
输出描述:
可能有多组测试数据，对于每组数据，
输出"Yes!”表示N是守形数。
输出"No!”表示N不是守形数。
示例1
输入
复制
25
4
输出
复制
Yes!
No!

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        string s1 = to_string(n);
        string s2 = to_string(n*n);

        s2 = s2.substr(s2.size()-s1.size(), s2.size());

        if (s1 == s2)
            cout << "Yes!" << endl;
        else
            cout << "No!" << endl;
    }
    return 0;
}
