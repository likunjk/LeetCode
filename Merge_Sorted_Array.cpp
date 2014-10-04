class Solution {
public:
    // 最有效的方法是：确定最后一个元素的位置，然后从后往前合并
    void merge(int A[], int m, int B[], int n) 
    {
        int k = n+m-1;
        int i,j;
        for(i=m-1, j=n-1; i>=0 && j>=0; )
        {
            if(A[i] >= B[j])
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
        while(i>=0)
        {
            A[k--] = A[i--];
        }
        while(j>=0)
        {
            A[k--] = B[j--];
        }
        return ;
    }
};
