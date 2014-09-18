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

    ListNode* listReverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *p = head;   
        while(p->next != NULL)  //->nextp为需要反转的节点
        {
            ListNode *q = p->next;    //使用一个节点保存，能省去不少麻烦
            p->next = q->next;
            
            q->next = head;
            head = q;
        }
        return head;
    }

    //思路：将后半部分链表反转，然后前后2个链表一一链接起来
    //注意：为了便于处理，当个数为奇数时，将多余的那个节点分配在前面
    void reorderList(ListNode *head) 
    {
        // 常规的检查必不可少
        if(head==NULL || head->next==NULL)
            return ;
            
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        
        while(p2->next != NULL)
        {
            p2 = p2->next;
            if(p2->next != NULL)  
            {
                p2 = p2->next;
                p1 = p1->next;
            }
            else//说明节点个数为奇数
            {
                p1 = p1->next;  //此时p1指向中间节点
                break;
            }
        }
        
        p2 = listReverse(p1->next); //反转后半段链表
        p1->next = NULL;    //将前半段链表的结尾指向NULL
        
        //因为这里的head不能改变，不能自己先建一个头结点，所以对前后链表的第一个节点需要特殊处理
        p1 = head->next;    //p1要优先处理，不然下面的操作会改变head的next指针
        
        ListNode *p = head; 
        p->next = p2;
        p = p->next;
        
        p2 = p2->next;
        while(p1!=NULL && p2!=NULL) //按顺序合并链表
        {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
            
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        if(p1!=NULL)    //当p1!=NULL时，说明节点个数为奇数，直接将前半段的最后一个节点链上去
        {
            p->next = p1;
            p = p->next;
        }
        p->next = NULL; //将链表的最后指向NULL
        
        return ;
    }
};
