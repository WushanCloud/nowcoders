请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值
测试样例：
1,2
返回：3

int addAB(int A, int B) {
    // write code here
//法一
	/*int C = 0;
	while (A)
	{
		C = (A & B) << 1;
		B = A ^ B;
		A = C;
	}
	return B;*/
//法二
	if (!A)
		return B;
	return addAB((A & B) << 1, A^B);
}

