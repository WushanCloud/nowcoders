
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。

给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。

测试样例：
2,2
返回：2

class Robot {
public:
    void fun( int i, int j, int x, int y, int& num)
{
    if (i == x && j == y)
        return;
    if (i == x || j == y)
    {
        num++;
        return;
    }
    fun(i+1, j, x, y, num);
    fun(i, j+1, x, y, num);
}

int countWays(int x, int y) {
    // write code here
    int arr[12][12] = { 0 };
    int num = 0;
    fun( 1, 1, x, y, num);
    return num;
}
};
