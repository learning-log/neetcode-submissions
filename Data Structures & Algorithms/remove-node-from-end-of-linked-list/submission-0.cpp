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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* last = dummy;
        while(n!=0){
            last = last ->next;
            n--;
            
        }

        ListNode* st = dummy;
        while(last->next){
            last = last->next;
            st = st->next;
        }

        st->next = st->next->next;
        return dummy->next;
    }
};
