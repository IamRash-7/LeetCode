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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        int len1=0, len2=0;
        while(d1!=NULL)
        {
            len1++;
            d1 = d1->next;
        }
        while(d2!=NULL)
        {
            len2++;
            d2 = d2->next;
        }
        d1=headA;
        d2 = headB;
        if(len1<len2)
        {
            swap(d1,d2);
            swap(len1,len2);
        }
        for(int i=0;i<len1-len2;i++)
        {
            d1 = d1->next;
        }
        while(d1!=NULL)
        {
            if(d1==d2)
                return d1;
            d1 = d1->next;
            d2 = d2->next;
        }
        return NULL;
    }
};