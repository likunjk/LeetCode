/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    //O(n)时间复杂度，O(n)的空间复杂度，需要使用unordered_map来存储节点的映射关系
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(head==NULL)
            return NULL;
        
        // 因为指针实质上就是整数，所以不用自己重载hash_value函数以及==运算符
        unordered_map<RandomListNode*, RandomListNode*> ump;
        
        RandomListNode *newHead = new RandomListNode(head->label);
        ump[head] = newHead;
        
        RandomListNode *p1 = head;
        RandomListNode *p2 = newHead;
        
        while(p1->next!=NULL)
        {
            RandomListNode *tp = new RandomListNode(p1->next->label);
            ump[p1->next] = tp;
            
            p2->next = tp;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p1 = head;
        p2 = newHead;
        while(p1!=NULL)
        {
            if(p1->random != NULL)
                p2->random = ump[p1->random];
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return newHead;
    }
};
