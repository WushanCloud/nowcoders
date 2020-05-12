题目描述
北京大学对本科生的成绩施行平均学分绩点制（GPA）。既将学生的实际考分根据不同的学科的不同学分按一定的公式进行计算。 公式如下： 实际成绩 绩点 90——100 4.0 85——89 3.7 82——84 3.3 78——81 3.0 75——77 2.7 72——74 2.3 68——71 2.0 64——67 1.5 60——63 1.0 60以下 0 1．一门课程的学分绩点=该课绩点*该课学分 2．总评绩点=所有学科绩点之和/所有课程学分之和 现要求你编写程序求出某人A的总评绩点（GPA）。
输入描述:
第一行 总的课程数n（n<10）；
第二行 相应课程的学分（两个学分间用空格隔开）；
第三行 对应课程的实际得分；
此处输入的所有数字均为整数。
输出描述:
输出有一行，总评绩点，精确到小数点后2位小数。（printf("%.2f",GPA);）
示例1
输入
复制
5
4 3 4 2 3
91 88 72 69 56
输出
复制
2.52

#include <iostream>
using namespace std;

double func(int num)
{
    if (num >= 90)
        return 4.0;
    if (num >= 85)
        return 3.7;
    if (num >= 82)
        return 3.3;
    if (num >= 78)
        return 3.0;
    if (num >= 75)
        return 2.7;
    if (num >= 72)
        return 2.3;
    if (num >= 68)
        return 2.0;
    if (num >= 64)
        return 1.5;
    if (num >= 60)
        return 1.0;
    return 0.0;
}

int main()
{
    int n = 0; // 总课程数
    cin >> n;
    int *arr = new int[n]; // 对应学分
    int *brr = new int[n]; // 实际得分
    
    double Sarr = 0.0; // 学分和
    double Scrr = 0.0; // 绩点和
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        Sarr += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
        Scrr += arr[i] * func(brr[i]);
    }
    printf("%.2f",Scrr/Sarr);
    
    return 0;
}
