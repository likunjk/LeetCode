class Solution {
public:
    // 没有重复元素，处理起来很舒心啊，画个图最好理解了
    int search(int A[], int n, int target) 
    {
        int left = 0;
        int right = n-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(A[mid]==target)  //找到啦
                return mid;
            else if(A[mid] >= A[0])  //mid位于前半段, 注意取到等号
            {
                if(target < A[mid] && target >= A[0])   //只有这种情况，target才位于左边
                    right = mid-1;
                else
                    left = mid+1;
                    
            }
            else
            {
                if(target > A[mid] && target <= A[n-1]) //只有这种情况，target才位于右边
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};
