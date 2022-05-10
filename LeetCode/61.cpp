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
    int length(ListNode* head) {
        int c = 0;
        while(head) {
            ++c;
            head = head -> next;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int l = length(head);
        k %= l;
        if(k == 0) {
            return head;
        }
        k = l - k - 1;
        ListNode* temp = head;
        {
            int c = 0;
            while(c < k) {
                ++c;
                temp = temp -> next;
            }
        }
        ListNode* nhead = temp -> next;
        temp -> next = nullptr;
        {
            ListNode* t = nhead;
            while(t -> next) {
                t = t -> next;
            }
            t -> next = head;
        }
        return nhead;
    }
};
