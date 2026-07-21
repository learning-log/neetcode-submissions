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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        int any_up = 1;
        while(any_up){
            any_up = 0;
            ListNode* pot;
            int idx = -1;
            int element_value = 100000;
            for(int i=0;i<lists.size();i++){
                
                
                if(!lists[i]){
                    continue;
                }
                if(element_value>lists[i]->val){
                    element_value = lists[i]->val;
                    pot = lists[i];
                    idx = i;
                    any_up++;
                }
            }

            if(any_up){
                temp ->next = pot;
                temp = temp->next;
                lists[idx] = lists[idx]->next;
            }
        }
        return dummy->next;
    }
};
