class Solution {
public:
    int singleNumber(int A[], int n) 
    {
        int ones = 0;   //若某位为1，则说明在该位1出现1次，为0则出现其他次
        int twos = 0;   //若某位为1，则说明在该位1出现2次，为0则出现其他次
        int threes = 0; //跟上面类似
        
        for(int i=0; i<n; ++i)
        {
            twos |= (ones & A[i]);   //若ones & A[i]后某位为1，则该位的1出现2次，说以twos该位应该为1
            ones ^= A[i];   //若ones和A[i]的某位相同，则说明该位的1是出现第2次，所以应该为0，刚好0和0异或也为0
            threes = ones & twos;    //当ones和twos的某位都为1时，说明该位出现了3次
            // 清空ones和twos中出现3次的位
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;    //相同的道理可知，twos中记录的是刚好出现2次的数字
    }
};
