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
    ListNode* removeN(ListNode* head, int n, int& c) {
        if(head == nullptr) {
            c = 0;
            return nullptr;
        }
        ListNode* nextO = removeN(head -> next, n, c);
        ++c;
        if(c == n) {
            return nextO;
        }
        else {
            head -> next = nextO;
            return head;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int z = 0;
        // return removeN(head, n, z);
        ListNode* start = new ListNode(0); start -> next = head; // Edge Case Resolved
        ListNode* slow = start, fast = start;
        for(int i = 1; i <= n + 1; ++i) {
            // Creating a gap of 'n' between slow and fast
            fast = fast -> next;
        }
        while(fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        // Now fast is at null
        // and slow and fast are at distance of n
        slow -> next = slow -> next -> next;
        return start -> next;
    }
};
