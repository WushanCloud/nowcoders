题目描述
考试题目和要点：

1、中文大写金额数字前应标明“人民币”字样。中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。（30分） 

2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，如￥ 532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。（30分） 

3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，如￥6007.14，应写成“人民币陆仟零柒元壹角肆分“。（
 

输入描述:
输入一个double数

输出描述:
输出人民币格式

示例1
输入
复制
151121.15
输出
复制
人民币拾伍万壹仟壹佰贰拾壹元壹角伍分


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> digit = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
vector<string> digits1 = { "", "拾","佰","仟"};
vector<string> digits2 = { "", "万","亿"};
vector<string> unit = { "角","分" };

string number(char c)
{
	return digit[c - '0'];
}

int main()
{
	string arr;
	while (cin >> arr)
	{
		string answer = "人民币";//答案
		string s1, s2;//分割

		size_t c = arr.find('.');
		s1 = arr.substr(0, c);
		reverse(s1.begin(), s1.end());
		s2 = arr.substr(c + 1, arr.size() - c - 1);

		if (s1.size() == 1 && s1[0] == '0');
		else {
			int temp = 0;
			for (int i = s1.size() - 1, j = (s1.size() - 1) / 4; i >= 0; i--)
			{
				if (s1[i] != '0')
				{
					if (s1.size() > 1 && i == s1.size() - 1 && s1[i] == '1')
						answer += digits1[i % 4];
					else
						answer += number(s1[i]) + digits1[i % 4];
					temp = 0;
				}
				else if (temp == 0)
				{
					answer += number('0');
					temp = 1;
				}
				if ((i) % 4 == 0)
				{
					answer += digits2[j--];
				}
			}
			//修饰
			if (s1[0] == '0')
			{
				answer.pop_back();
				answer.pop_back();
			}
			
			answer += "元";
			if (s2[0] == '0' && s2[1] == '0')
			{
				answer += "整";
			}
		}
		if (s2[0] != '0' || s2[1] != '0')
		{
			if (s2[0] != '0')
				answer += number(s2[0]) + unit[0];
			if (s2[1] != '0')
				answer += number(s2[1]) + unit[1];
		}
		cout << answer << endl;
	}
	return 0;
}
