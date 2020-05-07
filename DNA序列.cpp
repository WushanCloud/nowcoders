链接：https://www.nowcoder.com/questionTerminal/e8480ed7501640709354db1cc4ffd42a
来源：牛客网

一个DNA序列由A/C/G/T四个字母的排列组合组成。G和C的比例（定义为GC-Ratio）是序列中G和C两个字母的总的出现次数除以总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。因为高的GC-Ratio可能是基因的起始点。

给定一个很长的DNA序列，以及要求的最小子序列长度，研究人员经常会需要在其中找出GC-Ratio最高的子序列。
 


输入描述:
输入一个string型基因序列，和int型子串的长度



输出描述:
找出GC比例最高的子串,如果有多个输出第一个的子串

示例1
输入
AACTGTGCACGACCTGA
5
输出
GCACG


#include <iostream>
#include <string>
using namespace std;

int func(string str, int begin, int end)
{
    int sum = 0;
    for(begin; begin < end; begin++)
    {
        if (str[begin] == 'C' || str[begin] == 'G')
            sum++;
    }
    return sum;
}

int main()
{
    string str;
    int N = 0;
    while (cin >> str >> N)
    {
        int begin = 0;
        int num = 0;

        int temp = 0;
        for (int i = 0; i <= str.size()-N; i++)
        {
            temp = func(str, i, i + N);
            if (temp > num)
            {
                num = temp;
                begin = i;
            }
        }

        for (int i = begin; i < begin+N; i++)
            cout << str[i];
        cout << endl;
    }
    
    return 0;
}
