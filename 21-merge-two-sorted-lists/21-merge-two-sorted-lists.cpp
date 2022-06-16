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
        if(list1==NULL || list2==NULL)
        {
            if(list1==NULL)
                return list2;
            else if(list2==NULL)
                return list1;
            else
                return NULL;
        }
        int maxi=0;
        if(list1->val <= list2->val)
        {
            maxi = list1->val;
            list1 = list1->next;
        }
        else
        {
            maxi = list2->val;
            list2 = list2->next;

        }
        ListNode *ptr = new ListNode(maxi);
        ListNode *res = ptr;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                ptr->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                ptr->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        while(list1!=NULL)
        {
            ptr->next = new ListNode(list1->val);
            list1 = list1->next;
            ptr = ptr->next;
        }
        while(list2!=NULL)
        {
            ptr->next = new ListNode(list2->val);
            list2 = list2->next;
            ptr = ptr->next;
        }
        // list1->next = list2;
        return res;
    }
};