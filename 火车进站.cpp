链接：https://www.nowcoder.com/questionTerminal/97ba57c35e9f4749826dc3befaeae109
来源：牛客网

给定一个正整数N代表火车数量，0<N<10，接下来输入火车入站的序列，一共N辆火车，每辆火车以数字1-9编号。要求以字典序排序输出火车出站的序列号。

输入描述:
有多组测试用例，每一组第一行输入一个正整数N（0<N<10），第二行包括N个正整数，范围为1到9。



输出描述:
输出以字典序从小到大排序的火车出站序列号，每个编号以空格隔开，每个输出序列换行，具体见sample。

示例1
输入
3
1 2 3
输出
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> vs;

void pullin(vector<int>& train1, vector<int>& train2, vector<int>& train3)
{
	//当没有可进站火车和火车全部出站时结束
	if (train1.empty() && train2.empty())
	{
		vs.push_back("");
		for (int i = 0;i < train3.size();i++)
		{
			vs[vs.size() - 1] += (train3[i]+'0');
			vs[vs.size() - 1] += ' ';
		}
		return;
	}
	else
	{
		if (!train2.empty())
		{
			//出栈
			train3.push_back(train2.back());
			train2.pop_back();
			pullin(train1, train2, train3);
			train2.push_back(train3.back());
			train3.pop_back();
		}
		if (!train1.empty())
		{
			//进栈
			train2.push_back(train1.back());
			train1.pop_back();
			pullin(train1, train2, train3);
			train1.push_back(train2.back());
			train2.pop_back();
		}
	}
}

int main()
{
	//火车进站，火车停留，火车出站
	int N = 0; // 火车数量
    while(cin >> N)
    {
        vector<int> train1(N);
        vector<int> train2;
        vector<int> train3;

        for (int i = N-1; i >=0; i--)
        {
            cin >> train1[i];
        }

        pullin(train1, train2, train3);

        sort(vs.begin(), vs.end());

        for (int i = 0; i < vs.size(); i++)
        {
            cout << vs[i] << endl;
        }
    }
	return 0;
}
