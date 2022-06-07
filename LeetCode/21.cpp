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
        ListNode* head = nullptr, *tail = nullptr;
        while(list1 || list2) {
            if(((list1 && list2) && (list1 -> val < list2 -> val)) || ((list1 && !list2))) {
                if(!head) {
                    head = tail = list1; list1 = list1 -> next;
                }
                else {
                    tail -> next = list1; list1 = list1 -> next; tail = tail -> next;
                }
            }
            else {
                if(!head) {
                    head = tail = list2; list2 = list2 -> next;
                }
                else {
                    tail -> next = list2; list2 = list2 -> next; tail = tail -> next;
                }
            }
        }
        return head;
    }
};
