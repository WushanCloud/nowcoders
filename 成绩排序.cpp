题目描述
查找和排序

题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。

示例：
jack      70
peter     96
Tom       70
smith     67

从高到低  成绩
peter     96
jack      70
Tom       70
smith     67

从低到高

smith     67

jack      70
Tom      70
peter     96

输入描述:
输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开。

输出描述:

按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开

示例1
输入
3
0
fang 90
yang 50
ning 70

输出
fang 90
ning 70
yang 50



#include <iostream>
#include <string>
using namespace std;
struct student
{
    string name;
    int grade;
};

int main()
{
    int N = 0;
    int key;
    while (cin >> N >> key)
    {
        student* p = new student[N];

        for (int i = 0; i < N; i++)
        {
            cin >> p[i].name >> p[i].grade;
        }

        
        switch (key)
        {
        case 0:
            for (int i = 0; i < N-1; i++)
            {
                for (int j = 0; j < N-i-1; j++)
                {
                    if (p[j].grade < p[j + 1].grade)
                        swap(p[j], p[j + 1]);
                }
            }
            break;
        case 1:
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = 0; j < N - i - 1; j++)
                {
                    if (p[j].grade > p[j + 1].grade)
                        swap(p[j], p[j + 1]);
                }
            }
            break;
        default:
            break;
        }
        for (int i = 0; i < N; i++)
        {
            cout << p[i].name << " " << p[i].grade << endl;
        }
    }
    
    return 0;
}
