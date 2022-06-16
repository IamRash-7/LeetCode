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
    void deleteNode(ListNode* node) {
        while(node->next != NULL)
        {
            int temp = node->val;
            node->val = node->next->val;
            node->next->val = temp;
            if(node->next->next == NULL)
                node->next = node->next->next;
            else
                node = node->next;
        }
    }
};