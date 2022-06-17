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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode* ptr1 = new ListNode(0);
        ptr1->next = head;
        int cnt = 0;
        while(ptr1->next!=NULL)
        {
            ptr1 = ptr1->next;
            cnt++;
        }
        ListNode* ptr2 = head;
        for(int i=0;i<(cnt- k%cnt -1);i++)
        {
            ptr2 = ptr2->next;
        }
        ptr1->next = head;
        head = ptr2->next;
        ptr2->next = NULL;
        return head;
    }
};