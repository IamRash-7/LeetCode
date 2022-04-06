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
        ListNode* st = new ListNode(0);
        ListNode* tmp = st;
        head = head->next;
        int cnt = 0;
        while(head!=NULL)
        {
            if(head->val == 0)
            {
                st->next = new ListNode(cnt);
                st = st->next;
                cnt = 0;
            }
            else
            {
                cnt+= head->val;
            }
            head = head->next;
        }
        return tmp->next;
    }
};