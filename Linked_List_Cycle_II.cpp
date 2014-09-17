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
    // 可以证明，当p1和p2指针相遇时，这时候p1环还没走完，p2刚好走了1圈多。
    // 此时若p3指针从头开始，p1和p3每次都走一步，当他们相遇时，就是环的入口
    // 画个图一下子就明白了
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while(p2->next!=NULL)
        {
            p2 = p2->next;
            if(p2->next!=NULL)
            {
                p2 = p2->next;
                p1 = p1->next;
                if(p1==p2)  //为了求环的入口，这里必须是严格的p1每次1步，p2每次2步
                    break;
            }
            else
                return NULL;
        }
        if(p2->next==NULL)
            return NULL;
        // 如果能够执行下面的代码，说明是存在环的
        ListNode *p3 = head; //初始p=head时就相当于p走了1步
        p1 = p1->next;
        while(p1 != p3)
        {
            p1 = p1->next;
            p3 = p3->next;
        }
        return p1;  //相遇点即是环的入口
    }
};
