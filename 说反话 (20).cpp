链接：https://www.nowcoder.com/questionTerminal/aced908691df4ebca6744f9fbd437749
来源：牛客网

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入描述:
测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。


输出描述:
每个测试用例的输出占一行，输出倒序后的句子。
示例1
输入
Hello World Here I Come
输出
Come I Here World Hello


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        int pos = 0;
        while ((pos = s.rfind(" ")) != s.npos)
        {
            cout << s.substr(pos+1, s.size()) << " ";
            s = s.substr(0,pos);
        }
        cout << s << endl;
    }
    return 0;
}
