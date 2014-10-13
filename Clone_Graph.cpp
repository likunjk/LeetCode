/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    //先递归建立所有的节点，但是要保存值和节点指针的一一对应关系
    void helper1(unordered_map<int, UndirectedGraphNode*> &ump, UndirectedGraphNode *node)
    {
        UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
        ump[node->label] = p;
        for(int i=0; i<node->neighbors.size(); ++i)
        {
            UndirectedGraphNode *tt = node->neighbors[i];
             //这个条件很重要，不然会陷入死循环，因为题目中存在节点自己指向自己
            if(ump.find(tt->label)==ump.end()) 
                helper1(ump, tt);
        }
    }
    
    //递归建立节点的关系
    void helper2(unordered_map<int, UndirectedGraphNode*> &ump, unordered_set<int> &ust, UndirectedGraphNode *root)
    {
        UndirectedGraphNode *p = ump[root->label];
        ust.insert(root->label);    //用来记录每个节点是否已经操作过
        for(int i=0; i<root->neighbors.size(); ++i)
        {
            UndirectedGraphNode *tt = root->neighbors[i];
            p->neighbors.push_back(ump[tt->label]);
            if(ust.find(tt->label)==ust.end())
                helper2(ump, ust, tt);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if(node==NULL)
            return node;
        
        // 首先创建节点，并建立label和节点之间的映射关系
        unordered_map<int, UndirectedGraphNode*> ump;
        helper1(ump, node);
        
        // 建立节点之间关系
        unordered_set<int> ust;
        helper2(ump, ust, node);
        
        return ump[node->label];
    }
};
