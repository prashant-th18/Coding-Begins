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
        if(k == 1) return head;
        int len = 0;
        {
            ListNode* temp = head;
            while(temp) ++len, temp = temp -> next;
        }
        ListNode *hh = nullptr, *a = nullptr, *b = nullptr, *last = nullptr, *plast = nullptr;
        for(int i = 0; i < len / k; ++i) {
            if(b == nullptr) b = head;
            if(last == nullptr) last = b;
            else {
                plast = last, last = b;
            }
            a = b;
            b = b -> next;
            for(int j = 0; j < k - 1; ++j) {
                ListNode* temp = b -> next;
                b -> next = a;
                a = b;
                b = temp;
            }
            if(i > 0) {
                plast -> next = a;
            }
            else {
                hh = a;
            }
        }
        last -> next = b;
        return hh;
    }
};
