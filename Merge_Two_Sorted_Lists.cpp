/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        if(l1==NULL)    //常规的判断还是可以的
            return l2;
        if(l2==NULL)
            return l1;
            
        ListNode *head = new ListNode(0);   //使用一个无用的头结点来方便后续的处理
        ListNode *p = head;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if(l1!=NULL)    //相对数数组来说，链表的合并在处理后续部分时就很方便
            p->next = l1;
        if(l2!=NULL)
            p->next = l2;
            
        return head->next;
    }
};
