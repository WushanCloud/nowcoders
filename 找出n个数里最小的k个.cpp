
找出n个数里最小的k个

输入描述:
每个测试输入包含空格分割的n+1个整数，最后一个整数为k值,n
不超过100。


输出描述:
输出n个整数里最小的k个数。升序输出
示例1
输入
3 9 6 8 -10 7 -11 19 30 12 23 5
输出
-11 -10 3 6 7

#include <iostream>
using namespace std;

void Ksort(int *arr, int begin, int end, int K)
{
    if (begin >= end)
        return;
    if (begin > K)
        return;
    int left = begin;
    int right = end;
    int key = arr[end];
    while (left < right)
    {
        while(left < right && arr[left] < key)
            left++;
        while(left < right && arr[right] >= key)
            right--;
        swap(arr[left], arr[right]);
    }
    swap(arr[right], arr[end]);
    Ksort(arr, begin, right-1, K);
    Ksort(arr, right+1, end, K);
}

int main()
{
    int arr[101] = {0};
    int i = 0;
    while(scanf("%d", &arr[i]) == 1)i++;
    Ksort(arr,0,i-2,arr[i-1]);
    for (int j = 0; j < arr[i-1]-1; j++)
        cout << arr[j]<< " ";
    cout << arr[arr[i-1]-1];
    return 0;
}
