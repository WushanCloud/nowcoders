题目描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。


处理：


1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），对相同的错误记录（净文件名（保留最后16位）称和行号完全匹配）只记录一条，错误计数增加；


2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；


3、 输入的文件可能带路径，记录文件名称不能带路径。


输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：

示例1
输入
复制
E:\V1R2\product\fpgadrive.c   1325
输出
复制
fpgadrive.c 1325 1


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyClass
{
public:
    MyClass()
    {
        line = 0;
        sum = 1;
    }
    bool operator==(const MyClass& w)const
    {
        if (s == w.s && line == w.line)
            return true;
        return false;
    }
    string s;
    int line;
    int sum;
};



int main()
{
    vector<MyClass> wrong;
    MyClass w;
    while (cin >> w.s >> w.line)
    {
        w.s = w.s.substr(w.s.rfind("\\")+1, w.s.size());
        if (w.s.size() > 16)
            w.s = w.s.substr(w.s.size() - 16, w.s.size());
        if (!wrong.empty())
        {
            int temp = 1;
            for (size_t i = 0; i < wrong.size(); i++)
            {
                if (w == wrong[i])
                {
                    temp = 0;
                    wrong[i].sum++;
                }
            }
            if (temp)
                wrong.push_back(w);
        }
        else
        {
            wrong.push_back(w);
        }
    }
    
    int N = 0;
    if (wrong.size() < 8)
        N = wrong.size();
    else
        N = 8;
    for (int i = wrong.size() - N; i < wrong.size(); i++)
    {
        cout << wrong[i].s << " " << wrong[i].line << " " << wrong[i].sum << endl;
    }
    return 0;
}
