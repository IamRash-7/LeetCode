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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car = 0;
        ListNode* ptr = new ListNode();
        ListNode* ans = ptr;
        while(l1!=NULL && l2!=NULL)
        {
            int sum = l1->val + l2->val + car;
            ptr->next = new ListNode(sum%10);
            car = sum/10;
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            ptr->next = new ListNode((car+l1->val)%10);
            car = (car+l1->val)/10;
            ptr = ptr->next;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            ptr->next = new ListNode((car+l2->val)%10);
            car = (car+l2->val)/10;
            ptr = ptr->next;
            l2 = l2->next;
        }
        if(car!=0)
            ptr->next = new ListNode(car);
        return ans->next;
    }
};