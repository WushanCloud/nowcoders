题目描述
输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。
输入描述:
测试数据有多组，输入n(1<=n<=200)，接着输入n个数，然后输入x。
输出描述:
对于每组输入,请输出结果。
示例1
输入
复制
2
1 3
0
输出
复制
-1


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        int x = 0;
        vector<int> nums;
        while(n--)
        {
            cin >> x;
            nums.push_back(x);
        }
        cin >> x;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
            {
                cout << i << endl;
                break;
            }
        }
        if (i == nums.size())
            cout << -1 << endl;
    }
    
    return 0;
}
