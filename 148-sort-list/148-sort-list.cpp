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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        priority_queue <int, vector<int>, greater<int>> gq;

        while(head!=NULL)
        {
            gq.push(head->val);
            head = head->next;
        }
        ListNode* t = new ListNode(gq.top());
        ListNode* temp = t;
        gq.pop();
        while(!gq.empty())
        {
            t->next = new ListNode(gq.top());
            t= t->next;
            gq.pop();
        }
        return temp;
    }
};