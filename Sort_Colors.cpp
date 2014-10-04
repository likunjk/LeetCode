class Solution {
public:
    // 使用计数排序可以很好的解决这道题，可是题目后面要求只能扫描一遍数组。
    // 那么可以在扫描时将0放在数组的头部，2放在数组的尾部，1则不管
    void sortColors(int A[], int n) 
    {
        int zero = 0;
        int two = n-1;
        for(int i=0; i<n; )
        {
            if(A[i]==0)
            {
                swap(A[i++], A[zero++]);    //这里i可以自增，因为交换回来的元素不是0就是1，不可能是2
            }
            else if(A[i]==2)
            {
                // 如果下面的条件满足，则说明后面全部都是2
                if(i > two)    //这里一定要跳出去，不然会运行错误，比如[2,2]
                    break;
                swap(A[i], A[two--]); //这里进行交换之后，i不能自增，因为交换回来的元素可能是0
            }
            else
            {
                i++;
            }
        }
        return ;
    }
};
