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
    // 如果允许使用额外的空间，那么可以使用unordered_map来记录已经访问过的节点
    // 既然不允许的话，那么就只能使用快慢指针来解决问题
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL)
            return false;
        
        ListNode *p1 = head;    // p1每次走1步
        ListNode *p2 = head->next;  //p2每次走2步
        
        while(p2->next!=NULL)
        {
            p2 = p2->next;

            if(p1==p2)  //在这里也判断，可以减少判断次数
                return true;

            if(p2->next!=NULL)  //只有当p2可以走2步的时候，p1才走1步
            {
                p2 = p2->next;
                p1 = p1->next;
                if(p1==p2)
                    return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
