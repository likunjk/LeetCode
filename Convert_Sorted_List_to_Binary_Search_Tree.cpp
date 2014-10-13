/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //从测试数据来看，给定的链表节点个数不一定是奇数啊。应该按照完全二插搜索树来构造
    TreeNode *sortedListToBST(ListNode *head) 
    {
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)    //只有一个节点的情况
            return new TreeNode(head->val);
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        
        // 为了是二叉树平衡，当节点数为偶数时，默认左边比右边多1
        while(fast->next!=NULL)
        {
            fast = fast->next;
            if(fast->next != NULL)  // 这里的判断可以精确控制左右节点个数
            {
                slow = slow->next;  //当为奇数节点时，指向中间节点的前一个节点
                fast = fast->next;
            }
            else
                break;
        }
        
        TreeNode *p = new TreeNode(slow->next->val);
        p->right = sortedListToBST(slow->next->next);
        slow->next = NULL;
        p->left = sortedListToBST(head);
        
        return p;
    }
};
