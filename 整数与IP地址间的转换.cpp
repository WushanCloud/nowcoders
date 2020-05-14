题目描述
原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
一个长整数。
举例：一个ip地址为10.0.3.193
每段数字             相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001
组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。

 

的每段可以看成是一个0-255的整数，需要对IP地址进行校验

 

 

 

输入描述:
输入 
1 输入IP地址
2 输入10进制型的IP地址

输出描述:
输出
1 输出转换成10进制的IP地址
2 输出转换后的IP地址

示例1
输入
复制
10.0.3.193
167969729
输出
复制
167773121
10.3.3.193


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sip1;//转换前
    unsigned int nip1 = 0;//转换前
    while (cin >> sip1 >> nip1)
    {
        string sip2;//转换后
        unsigned int nip2 = 0;//转换后
        sip1 += '.';
        for (int i = 0; i < 4; i++)
        {
            string s = sip1.substr(0, sip1.find('.'));
            sip1 = sip1.substr(sip1.find('.') + 1, sip1.size());
            int num = atoi(s.c_str());
            for (int i = 0; i < 8; i++)
            {
                nip2 <<= 1;
                if (num & (1<<7))
                    nip2 |= 1;
                num <<= 1;
            }
        }
        cout << nip2 << endl;

        for (int i = 0; i < 4; i++)
        {   
            int num = 0;
            for (int j = 0; j < 8; j++)
            {
                num <<= 1;
                if (nip1 & (1 << 31))
                    num |= 1;
                nip1 <<= 1;
            }
            sip2 += to_string(num)+'.';
        }
        sip2.pop_back();
        cout << sip2 << endl;
    }
    return 0;
}
