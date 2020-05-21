链接：https://www.nowcoder.com/questionTerminal/79db907555c24b15a9c73f7f7d0e2471
来源：牛客网

大家应该都会玩“锤子剪刀布”的游戏：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入描述:
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代
表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。


输出描述:
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯
一，则输出按字母序最小的解。
示例1
输入
10<br/>C J<br/>J B<br/>C B<br/>B B<br/>B C<br/>C C<br/>C B<br/>J B<br/>B C<br/>J J
输出
5 3 2<br/>2 3 5<br/>B B

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int heads(char c)
{
    if(c == 'C')
	return 1;
    if(c == 'J')
	return 2;
    if(c == 'B')
	return 0;
}

int win(char c1, char c2)
{
    if (c1 == c2)
	return 1;
    if (c1 == 'C')
    {
	if(c2 == 'J')
	    return 0;
	else
	    return 2;
    }
    if(c1 == 'J')
    {
	if(c2 == 'C')
	    return 2;
	else
	    return 0;
    }
    if(c1 == 'B')
    {
	if(c2 == 'C')
	    return 0;
	else
	    return 2;
    }
}

char max(char c1, char c2, vector<int>& sum)
{
    if (sum[heads(c1)] >= sum[heads(c2)])
	    return c1;
    else
	    return c2;
}

int main()
{
    int N = 0;
    cin >> N;
    vector<int> sum1(3,0);//BCJ
    vector<int> sum2(3,0);//BCJ
    vector<int> ans(3,0);//胜 平 负
    while(N--)
    {
        char c1, c2;
        cin >> c1 >> c2;
	int i = win(c1,c2);
	++ans[i];
	if (i == 0)
	    ++sum1[heads(c1)];
	else if (i == 2)
	    ++sum2[heads(c2)];
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    cout << ans[2] << " " << ans[1] << " " << ans[0] << endl;
    char c1, c2;
    c1 = max(max('B', 'C', sum1), 'J', sum1);
    c2 = max(max('B', 'C', sum2), 'J', sum2);
    cout << c1 << " " << c2;
    return 0;
}
