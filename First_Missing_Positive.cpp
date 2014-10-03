class Solution {
public:
    // 思路：将每个元素放到它该出现的位置，比如4就放到位置3(下标从0开始)
    int firstMissingPositive(int A[], int n)
    {
        if(n==0)
            return 1;
        for(int i=0; i<n; ++i)
        {
            if(i != A[i]-1)
            {
                int preValue = A[i]; //前一个位置的值
                int nextPos = preValue-1;    //下一个位置
                // 要一个位置的值合法，并且下一个位置的值不合法，才进行处理
                while(preValue>=1 && preValue<=n && nextPos != A[nextPos]-1)
                {
                    int tt = A[nextPos];
                    A[nextPos] = preValue;
                    preValue = tt;
                    nextPos = preValue-1;
                }
                continue;
            }
        }
        for(int i=0; i<n; ++i)  //遍历一遍，看谁不存在
        {
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1; //说明都存在
    }
};
