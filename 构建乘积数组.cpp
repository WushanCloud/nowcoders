
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）



class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> B(A.size(),1);
        for (int i = 1; i <= A.size(); i++)
        {
            B[i] = A[i-1] * B[i-1];
        }
        int temp = 1;
        for (int i = A.size()-1-1; i >=0; i--)
        {
            temp *= A[i+1];
            B[i] *= temp;
        }
        return B;
    }
};
