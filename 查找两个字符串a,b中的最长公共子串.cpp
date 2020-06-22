查找两个字符串a,b中的最长公共子串

/*
题目描述
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        if (s1.size() > s2.size())
            swap(s1, s2);
        int sub = 0; // 截取的开始位置
        int sum = 0; // 截取的位数
        int len = 0; // 当前重复长度
        int maxlen = 0; // 重复最长长度
        
        for (size_t i = 0; i < s1.size(); i++)
        {
            for (size_t j = 0; j < s2.size(); j++)
            {
                size_t ti = i, tj = j;
                len = 0;
                while (s1[ti] == s2[tj])
                {
                    ti++; tj++;
                    len++;
                }
                if (len > maxlen)
                {
                    maxlen = len;
                    sub = i;
                    sum = ti - i;
                }
            }
        }
        cout << s1.substr(sub, sum) << endl;
    }
    return 0;
}
