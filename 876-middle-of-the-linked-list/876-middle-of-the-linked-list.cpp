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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* ptr = head;
        while(ptr!=NULL)
        {
            cnt++;
            ptr = ptr->next;
        }
        for(int i=0;i<cnt/2;i++)
        {
            head = head->next;
        }
        cout<<cnt;
        return head;
    }
};