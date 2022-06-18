/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* org = head;
        map<Node*, Node*> mp;
        while(org!=NULL)
        {
            Node* tmp = new Node(org->val);
            mp[org] = tmp;
            org = org->next;
        }
        org = head;
        while(org!=NULL)
        {
            mp[org]->next = mp[org->next];
            mp[org]->random = mp[org->random];
            org = org->next;
        }
        return mp[head];
    }
};