class Solution {
public:
    // 其实就是一个环路，将加气站头尾连起来，只要能够连续正常经过n个加气站，那么就说明我们可以完成环游
    // 结论：当从加气站i开始，经过i+1, i+2, ..., 最终无法到达j，那么从k(k>=i+1 && k<j)开始的加气站都无法到达j。
    // 证明：以i+1为例，既然能够从i到达i+1, 那么此时汽车里的剩余油量肯定是>=0的，如果我们在有>=0的油量的情况下都不能从i+1到达j，
    //       那么我们如何能在直接从i+1开始，初始油量为0的情况下到达j. 因此证明直接从i+1到j是不可能的。
    //       其余点同理可证。
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
    {
        int n = gas.size();
        
        int count = 0;
        int current = 0;
        for(int i=0; i<2*n; ++i)
        {
            int index = i%n;
            current += gas[index];
            
            if(current >= cost[index])
            {
                count++;
                current -= cost[index];
                if(count==n)
                {
                    //因为题目保证了结果的唯一性，因此可以直接返回
                    return i-n+1; 
                }
            }
            else    //说明从该点不能到达下一点，那么直接从下一点开始
            {
                count = 0;
                current = 0;
            }
        }
        
        return -1;  //不能完成环游
    }
};
