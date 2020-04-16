

有一组数，对于其中任意两个数组，若前面一个大于后面一个数字，则这两个数字组成一个逆序对。请设计一个高效的算法，计算给定数组中的逆序对个数。

给定一个int数组A和它的大小n，请返回A中的逆序对个数。保证n小于等于5000。

测试样例：
[1,2,3,4,5,6,7,0],8
返回：7

class AntiOrder {
public:
    int count(vector<int> A, int n) {
        // write code here
        int sum = 0;//总数
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (A[j] > A[j+1])
                {
                    swap(A[j],A[j+1]);
                    sum++;
                }
            }
        }
        return sum;
    }
};
