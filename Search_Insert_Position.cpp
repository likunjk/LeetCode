class Solution {
public:
    // 题目的意思通俗一点理解就是：又存在target，则返回它的位置；若不存在，则返回第一个大于它的元素的位置
    int searchInsert(int A[], int n, int target) 
    {
        int left = 0;
        int right = n-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                left = mid+1;
            else  //若right==mid则说明left==right，直接上right=mid-1,然后跳出循环
                right = (right!=mid) ? mid : mid-1; 
        }
        return left;
    }
};
