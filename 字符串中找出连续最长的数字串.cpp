

读入一个字符串str，输出字符串str中的连续最长的数字串

输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。


输出描述:
在一行内输出str中里连续最长的数字串。
示例1
输入
abcd12345ed125ss123456789
输出
123456789


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int max[2] = {0};
    int temp = 0;
    int i = 0;
    while (i < str.size())
    {
        if (str[i]>'9' || str[i]<'1')
        {
            i++;
            continue;
        }
        temp = 0;
        while (str[i]>='1' && str[i]<='9')
        {
            temp++;
            i++;
        }
        if (temp > max[0])
        {
            max[0] = temp;
            max[1] = i-temp;
        }
    }
    for (int j = max[1];j < max[1]+max[0];j++)
    {
        cout << str[j];
    }
    return 0;
}
