给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：


A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

输入描述:
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。


输出描述:
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。
示例1
输入
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出
30 11 2 9.7 9



#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits.h>
#include <vector>
using namespace std;

int main()
{
    int N = 0, num = 0;
    vector<int> A,B,C,D,E;
    cin >> N;
    while(N--)
    {
        cin >> num;
        switch(num % 5)
        {
            case 0:
                if (num % 2 == 0)
                    A.push_back(num);
                break;
            case 1:
                B.push_back(num);
                break;
            case 2:
                C.push_back(num);
                break;
            case 3:
                D.push_back(num);
                break;
            case 4:
                E.push_back(num);
                break;
            default:
                break;
        }
    }
    if (!A.empty())
        {
            int num = 0;
            for (auto x : A)
            {
                num += x;
            }
            cout << num << " ";
        }
        else
            cout << "N" << " ";
        if (!B.empty())
        {
            int num = 0;
            for (int i = 0; i < B.size(); i++)
            {
                num += B[i] * pow(-1, i);
            }
            cout << num << " ";
        }
        else
            cout << "N" << " ";
        if (!C.empty())
        {
            cout << C.size() << " ";
        }
        else
            cout << "N" << " ";
        if (!D.empty())
        {
            double num = 0;
            for (int i = 0; i < D.size(); i++)
            {
                num += D[i];
            }
            num /= D.size();
            cout <<fixed << setprecision(1) << num << " ";
        }
        else
            cout << "N" << " ";
        if (!E.empty())
        {
            int num = INT_MIN;
            for (auto x : E)
            {
                if (x > num)
                    num = x;
            }
            cout << num ;
        }
        else
            cout << "N" ;
    return 0;
}
