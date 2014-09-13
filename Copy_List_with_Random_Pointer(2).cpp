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
    //O(n)时间复杂度，O(1)的空间复杂度
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(head==NULL)
            return NULL;
        
        // 沿着next链复制节点
        RandomListNode *p = head;
        RandomListNode *clone = NULL;
        while(p!=NULL)
        {
            // 复制该节点，存放在其后面
            clone = new RandomListNode(p->label);
            
            clone->next = p->next;
            p->next = clone;
            
            p = clone->next;
        }
        
        //确定复制节点的random指针
        p = head;
        while(p!=NULL)
        {
            clone = p->next;
            if(p->random!=NULL) //这里很巧妙，直接确定复制节点的random指针
                clone->random = p->random->next;
            p = clone->next;
        }
        
        // 分离原链表和复制的链表
        RandomListNode *newHead = head->next;
        p = head;
        clone = newHead;
        while(clone->next != NULL)
        {
            p->next = clone->next;
            p = p->next;
            
            clone->next = p->next;
            clone = clone->next;
        }
        p->next = NULL; //一定要这样设置，就能保证不破坏原链表
        
        return newHead;
    }
};
