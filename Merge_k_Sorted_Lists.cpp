/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

struct Compare
{
    // 因为优先队列默认是大顶堆
    bool operator () (const ListNode *p1, const ListNode *p2) 
    {
        return p1->val > p2->val;
    }
};
 
class Solution {
public:
    // 时间复杂度为: O(nlogk),其中n为k个节点的总节点数之和
    // 与归并排序的合并类似，只不过归并是2路，这里是k路而已，采用最小堆
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        // 因为优先队列的构造函数中后两个参数是缺省的，若给最后一个赋值，则倒数第二个也要赋值
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        for(int i=0; i<lists.size(); ++i)
        {
            if(lists[i]!=NULL)
                q.push( lists[i] );   //加入队列的节点一定不为NULL
        }
        while(!q.empty())
        {
            ListNode *tt = q.top();
            q.pop();
            p->next = tt;
            p = p->next;
            if(tt->next!=NULL)  //链表较数组的好处在于可以方便的找到所属链表的下一个节点
            {
                q.push( tt->next );
            }
        }
        return head->next;
    }
};
