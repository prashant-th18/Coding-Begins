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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* thead = nullptr, *ttail = nullptr, *f = nullptr;
        if(!head) return head;
        else f = head -> next;
        while(head) {
            while(f && head -> val == f -> val) {
                f = f -> next;
            }
            if(head -> next == f) {
                if(thead == nullptr) thead = ttail = head;
                else {
                    ttail = ttail -> next = head;
                }
                head = head -> next;
                if(head && head -> next) f = head -> next;
                else f = nullptr;
            }
            else {
                head = f;
                if(head && head -> next) f = head -> next;
                else f = nullptr;
            }
        }
        if(ttail)
        ttail -> next = head;
        return thead;
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
