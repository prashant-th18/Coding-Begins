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
    ListNode* swapAdj(ListNode* head) {
        if(!head || !(head -> next)) return head;
        ListNode *s = head -> next;
        head -> next = swapAdj(s -> next);
        s -> next = head;
        return s;
    }
    ListNode* swapPairs(ListNode* temp) {
        return swapAdj(head);
        /*ListNode* head = nullptr, *tail = nullptr;
        while(temp) {
            if(!(temp -> next)) {
                tail -> next = temp;
                tail = tail -> next;
                tail = nullptr;
            }
            else {
                
            }
        }
        */
    }   
};
