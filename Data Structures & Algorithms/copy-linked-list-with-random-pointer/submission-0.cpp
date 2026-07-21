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
        unordered_map<Node*,Node*>mp;
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        while(temp){
            Node* new_ = new Node(temp->val);
            mp[temp] = new_;
            curr->next =  new_;
            curr = curr->next;
            temp = temp->next;
        }

        temp = head;
        curr = dummy->next;
        while(temp){
            Node* rand = temp->random;
            if(rand){
                curr->random = mp[rand];
            }
            curr = curr->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
