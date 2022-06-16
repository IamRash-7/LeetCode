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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* t = NULL;
        while(ptr!= NULL)
        {
            ListNode* temp = ptr->next;
            ptr->next = t;
            t = ptr;
            ptr = temp;
        }
        return t;
    }
};