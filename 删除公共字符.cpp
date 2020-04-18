
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

输入描述:
每个测试输入包含2个字符串


输出描述:
输出删除后的字符串
示例1
输入
They are students. 
aeiou
输出
Thy r stdnts.


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    for (int i = 0; i < str1.size();i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                str1.erase(i,1);
                i--;
                break;
            }
        }
    }
    cout << str1;
    return 0;
}
