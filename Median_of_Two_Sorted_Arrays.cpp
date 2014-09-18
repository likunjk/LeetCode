class Solution {
public:
    //寻找两个有序数组的第k小的元素，也就是合并后的第k个元素（从小到大）
    double findNumK(int A[], int m, int B[], int n, int k)
    {
        if(n < m)   // 为了方便处理，将长度短的放在前面
            return findNumK(B, n, A, m, k);
        
        //先处理一些特殊情况
        if(m==0)
            return B[k-1];
        if(k==1)    //当执行到这里时，说明A和B两个数组都不为空
            return min(A[0], B[0]);
        
        //下面处理一般情况
        int pa = min(k/2, m);   //这里的划分很关键，也正因为前面确定了m<n，这里才可以这样做
        int pb = k - pa;
        //当出现这种情况时，说明A数组的前pa个元素在合并后的数组中，一定处于前k个，现在我们是寻找第k个，因此可以直接跳过
        if(A[pa-1] < B[pb-1])   //下标从0开始
            return findNumK(A+pa, m-pa, B, n, k-pa);
        else if(A[pa-1] > B[pb-1])  //道理跟上面是一样的
            return findNumK(A, m, B+pb, n-pb, k-pb);
        else    //说明合并后，它们刚好处于第k的位置
            return A[pa-1];
    }

    // 好久不做这种题，都给忘记了
    // 思路：将其转化为求两个有序数组合并后的第k小的数
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        int sum = m+n;
        if(sum % 2==1) //说明是奇数，只需要返回中间的那个即可
            return findNumK(A, m, B, n, sum/2+1);
        else    //当为偶数时，需要返回中间两个数的和
            return ( findNumK(A, m, B, n, sum/2) + findNumK(A, m, B, n, sum/2+1) ) / 2;
    }
};
