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

    ListNode* mergeList(ListNode *p1, ListNode *p2)
    {
        if(p1==NULL)
            return p1;
        if(p2==NULL)
            return p1;
        ListNode *head = new ListNode(0);   //构造一个头结点，方便编码
        ListNode *p = head;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        
        if(p1!=NULL)
            p->next = p1;
        if(p2!=NULL)
            p->next = p2;
            
        return head->next;
    }

    // 从题目的要求来看，只能采用归并排序
    ListNode *sortList(ListNode *head) 
    {
        if(head==NULL || head->next==NULL)  //特殊情况特殊处理
            return head;
        
        //这里将p2指向第2个节点是有依据的，相当于他们都走了一次，p1走一步，p2走两步
        ListNode *p1 = head;
        ListNode *p2 = head->next;  
        while(p2->next!=NULL)
        {
            p2 = p2->next;
            
            //当p2能够走2次时，p1才移动，这样就能保证在结束时p1总是指向前半段的最后一个节点
            //这样就能从容取出后半段啦!!!
            if(p2->next!=NULL)  
            {
                p2 = p2->next;
                p1 = p1->next;
            }
            else
            {
                break;
            }
        }
        p2 = p1->next;  //将链表拆分成2部分
        p1->next = NULL;
        
        p2 = sortList(p2);  //递归拆分排序
        p1 = sortList(head);
        
        head = mergeList(p1, p2);  //有序链表的合并
        
        return head;
    }
};
