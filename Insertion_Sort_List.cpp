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
    // 使用插入排序模拟，不过每次只能从头结点开始比较
    ListNode *insertionSortList(ListNode *head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
            
        ListNode *p = head->next;
        ListNode *pre = head;   //保存p的前一个节点
        ListNode *p1 = NULL;
        ListNode *pre1 = NULL;  //保存p1的前一个节点
        while(p!=NULL)
        {
            p1 = head;
            pre1 = NULL;
            while(p1!=p && p1->val <= p->val)    //稳定排序啊
            {
                pre1 = p1;
                p1 = p1->next;
            }
            if(p1 != p) //说明当前节点应该位于p1的前面
            {
                ListNode *pp = p;   //保存当前节点,多使用一个节点，可以省去很多事情
                pre->next = p->next;
                p = pre->next;
                if(p1==head)    //对头结点要特殊处理
                {
                    pp->next = head;
                    head = pp;
                }
                else
                {
                    pre1->next = pp;
                    pp->next = p1;
                }
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
