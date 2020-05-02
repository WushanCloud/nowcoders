
验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。

例如：

1^3=1 

2^3=3+5 

3^3=7+9+11 

4^3=13+15+17+19 

 

接口说明

原型：


 /*
 功能: 验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。
 原型：
     int GetSequeOddNum(int m,char * pcSequeOddNum);
 输入参数：
     int m：整数(取值范围：1～100)
    
 返回值：
     m个连续奇数(格式：“7+9+11”);
 */

 public String GetSequeOddNum(int m)
 {
     /*在这里实现功能*/

     return null;
 }

输入描述:
输入一个int整数



输出描述:
输出分解后的string

示例1
输入
6
输出
31+33+35+37+39+41


#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    while(cin >> n)
    {
        int start = n*n - n + 1;
        for (int i = 0; i < n-1; i++)
            cout << start + 2*i << "+";
        cout << start + 2*(n-1) << endl;
    }
    return 0;
}
