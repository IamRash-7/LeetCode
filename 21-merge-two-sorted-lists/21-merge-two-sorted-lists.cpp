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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // cnt->next = list1;
        // while(list1!=NULL && list2!=NULL)
        // {
        //     if(list1->val >= list2->val)
        //     {
        //         list1 = list1->next;
        //         cnt = cnt->next;
        //     }
        //     else
        //     {
        //         cnt->next = list2;
        //         ListNode* tmp = list2->next;
        //         list2->next = list1;
        //         list2 = tmp;
        //     }
        // }
        // return list1;
        ListNode tail(INT_MIN); 
        ListNode* cnt = &tail;
        while(list1 && list2)
        {
            if(list1->val >= list2->val)
            {
                cnt->next = list2;
                list2 = list2->next;
            }
            else
            {
                cnt->next = list1;
                list1 = list1->next;
            }
            cnt = cnt->next;
        }
        if(list1)
            cnt->next = list1;     
        else
            cnt->next = list2; 
        return tail.next;
    }
};