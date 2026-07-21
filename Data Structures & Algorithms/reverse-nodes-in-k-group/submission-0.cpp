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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode *curr=head;
        while(true){
            ListNode* st,*prev,*next;
            st = curr;
            prev = nullptr;
            int count = 0;
            while(curr and count<k){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            if(count==k){
                st->next = curr;
                temp->next = prev;
                temp = st;
            }
            else{
                curr = prev;
                prev = nullptr;
                while(curr){
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    count++;
                }
                temp->next = prev;
                break;

            }

        }
        return dummy->next;
    }
};
