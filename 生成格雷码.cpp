链接：https://www.nowcoder.com/questionTerminal/50959b5325c94079a391538c04267e15
来源：牛客网

在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，请编写一个函数，使用递归的方法生成N位的格雷码。
给定一个整数n，请返回n位的格雷码，顺序为从0开始。
测试样例：
1
返回：["0","1"]

class GrayCode {
public:
    vector<string> getGray(int n) {
    // write code here
        vector<string> arr;
        if (n == 1)
        {
            arr.push_back("0");
            arr.push_back("1");
            return arr;
        }

        vector<string> temp = getGray(n-1);

        //每多一位，格雷码数量翻倍，一次正的，一次反的，连接起来
        for (int i = 0; i < temp.size(); i++)//正向
        {
            arr.push_back("0" + temp[i]);
        }
        for (int i = temp.size() - 1; i >= 0; i--)//反向
        {
            arr.push_back("1" + temp[i]);
        }

        return arr;
}
};

