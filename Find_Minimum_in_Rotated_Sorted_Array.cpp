class Solution {
public:
    // 很简单的旋转数组，没有重复元素
    int findMin(vector<int> &num) 
    {
        int n = num.size();
        
        int left = 0;
        int right = n-1;
        while(num[left] > num[right])   //这句话可以确保当前的[left, right]区间是有旋转的
        {
            int mid = (left+right)/2;
            if(num[mid] >= num[left])   //说明mid为左半部分
                left = mid+1;
            else
                right = mid;    //说明mid位于右半部分
        }
        return num[left];
    }
};
