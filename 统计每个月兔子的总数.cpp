题目描述
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？

输入描述:
输入int型表示month

输出描述:
输出兔子总数int型

示例1
9
输出
34

#include <iostream>
using namespace std;

int main()
{
    
    int month = 0;
    while (cin >> month)
    {
        int m1 = 1, m2 = 0, m3 = 0;
        for (int i = 1; i < month; i++)
        {
            m3 += m2;
            m2 = m1;
            m1 = m3;
        }
        cout << m1 + m2 + m3 << endl;
    }
    return 0;
}
