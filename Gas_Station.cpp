class Solution {
public:
    // 其实就是一个环路，将加气站头尾连起来，只要能够连续正常经过n个加气站，那么就说明我们可以完成环游
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
