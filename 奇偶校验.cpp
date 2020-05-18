题目描述
输入一个字符串，然后对每个字符进行奇校验，最后输出校验后的二进制数(如'3’，输出：10110011)。
输入描述:
输入包括一个字符串，字符串长度不超过100。
输出描述:
可能有多组测试数据，对于每组数据，
对于字符串中的每一个字符，输出按题目进行奇偶校验后的数，每个字符校验的结果占一行。
示例1
输入
复制
3
3a
输出
复制
10110011
10110011
01100001



#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            int c = s[i];
            int sum = 0;
            string sc;
            
            for (size_t j = 0; j < 7; j++)
            {
                if (c % 2)
                    sc += '1', sum++;
                else
                    sc += '0';
                c /= 2;
            }
            if (sum % 2 == 0)
                sc += '1';
            else
                sc += '0';
            reverse(sc.begin(), sc.end());
            cout << sc << endl;
        }
    }
    return 0;
}
