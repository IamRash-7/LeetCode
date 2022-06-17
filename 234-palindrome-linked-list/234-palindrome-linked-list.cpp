/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverse(slow->next);
        
        slow = slow->next;
        ListNode* dummy = head;
        while(slow!=NULL)
        {
            if(slow->val != dummy->val)
                return false;
            slow = slow->next;
            dummy=dummy->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* nex = NULL;
        while(head!=NULL)
        {
            nex = head->next;
            head->next = pre;
            pre = head;
            head = nex;
        }
        return pre;
    }
};