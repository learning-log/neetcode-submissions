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
    ListNode* reverse(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        ListNode* next = head->next;
        ListNode* n_h = reverse(next);
        next->next = head;
        head->next = nullptr;
        return n_h;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!fast){
            return ;
        }
        if(!fast->next){
            return ;
        }
        fast = fast->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* second = reverse(fast);
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* temp = head;
        while(temp){
            curr->next = temp;
            temp = temp->next;
            curr = curr->next;
            if(second){
                curr->next = second;
                second = second->next;
                curr = curr->next;
            }
        }
        // return dummy->next;

    }
};
