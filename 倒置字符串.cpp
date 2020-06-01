链接：https://www.nowcoder.com/questionTerminal/b0ae3d72444a40e2bb14af7d4cb856ba
来源：牛客网

将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I

输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100


输出描述:
依次输出倒置之后的字符串,以空格分割
示例1
输入
I like beijing.
输出
beijing. like I

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    getline(cin, s);
    while(s != "")
    {
        int tmp = s.rfind(" ");
        if (tmp!= s.npos)
        {
            cout << s.substr(tmp+1) << " ";
            s = s.substr(0, tmp);
        }
        else
        {
            cout << s;
            s = "";
        }
    }
    return 0;
}
