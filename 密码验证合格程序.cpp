
题目描述
密码要求:

1.长度超过8位

2.包括大小写字母.数字.其它符号,以上四种至少三种

 
3.不能有相同长度超2的子串重复

 
说明:长度超过2的子串


输入描述:
一组或多组长度超过2的子符串。每组占一行

输出描述:
如果符合要求输出：OK，否则输出NG

示例1
输入
复制
021Abc9000
021Abc9Abc1
021ABC9000
021$bc9000
输出
复制
OK
NG
NG
OK



#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

bool func1(string passwd)
{
	if (passwd.size() <= 8)
		return false;
	return true;
}
bool func2(string passwd)
{
	vector<int> sum(4, 0);
	for (size_t i = 0; i < passwd.size(); i++)
	{
		if (passwd[i] >= 'A' && passwd[i] <= 'Z')
			sum[0]++;
		else if (passwd[i] >= 'a' && passwd[i] <= 'z')
			sum[1]++;
		else if (passwd[i] >= '0' && passwd[i] <= '9')
			sum[2]++;
		else
			sum[3]++;
	}
	int temp = 0;
	for (size_t i = 0; i < sum.size(); i++)
	{
		if (sum[i] == 0)
			temp++;
		if (temp >= 2)
			return false;
	}
	return true;
}
bool func3(string passwd)
{
	for (size_t i = 0; i < passwd.size(); i++)
	{
		if (passwd.find(passwd.substr(i, 3), i + 2) != passwd.npos)
			return false;
	}
	return true;
}
int main()
{
	string passwd;
	while (cin >> passwd)
	{
		if (func1(passwd) && func2(passwd) && func3(passwd))
			cout << "OK" << endl;
		else
			cout << "NG" << endl;
	}
	return 0;
}
