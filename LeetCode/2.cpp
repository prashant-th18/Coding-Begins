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
#include<stack>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr, *back = nullptr;
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 != nullptr && l2 != nullptr) {
                int res = (l1 -> val) + (l2 -> val);
                res += carry;
                int b = res % 10;
                int c = res / 10;
                carry = c;
                ListNode* temp = new ListNode(b);
                if(head == nullptr) {
                    head = back = temp;
                }
                else {
                    back -> next = temp;
                    back = back -> next;
                }
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            else if(l1) {
                int res = (l1 -> val) + carry;
                carry = res / 10;
                ListNode* temp = new ListNode(res % 10);
                back -> next = temp;
                back = back -> next;
                l1 = l1 -> next;
            }
            else {
                int res = (l2 -> val) + carry;
                carry = res / 10;
                ListNode* temp = new ListNode(res % 10);
                back -> next = temp;
                back = back -> next;
                l2 = l2 -> next;
            }
        }
        if(carry) {
            back -> next = new ListNode(carry);
        }
        return head;
    }
};
