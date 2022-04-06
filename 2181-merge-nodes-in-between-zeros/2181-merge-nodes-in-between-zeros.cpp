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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* st = head->next;
        while(st!=NULL)
        {
            ListNode* end = st;
            int cnt = 0;
            while(end->val !=0)
            {
                cnt+= end->val;
                end = end->next;      
            }
            st->val = cnt;
            st->next = end->next;
            st = st->next;
        }
        return head->next;
    }
};