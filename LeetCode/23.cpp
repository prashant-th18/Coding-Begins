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
    ListNode* mergeKListss(vector<ListNode*>& lists) {
        ListNode* head = nullptr, *tail = nullptr;
        int ind = -1;
        ListNode* temp = nullptr;
        while(1) {
            ind = -1; temp = nullptr;
            for(int i = 0; i < lists.size(); ++i) {
                if(!lists[i]) continue;
                if(!temp) {
                    temp = lists[i];
                    ind = i;
                }
                else if(temp -> val > lists[i] -> val) {
                    ind = i;
                    temp = lists[i];
                }
            }
            if(ind == -1) break;
            if(!head) {
                head = tail = lists[ind];
                lists[ind] = lists[ind] -> next;
            }
            else {
                tail -> next = lists[ind];
                lists[ind] = lists[ind] -> next;
                tail = tail -> next;
            }
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;
        for(int i = 0; i < lists.size(); ++i) {
            while(lists[i]) {
                temp.emplace_back(lists[i] -> val);
                lists[i] = lists[i] -> next;
            }
        }
        sort(temp.begin(), temp.end());
        ListNode* head = nullptr, *tail = nullptr;
        for (int i = 0; i < temp.size(); i++) {
            if(!head) {
                head = tail = new ListNode(temp[i]);
            }
            else {
                tail -> next = new ListNode(temp[i]);
                tail = tail -> next;
            }
        }
        return head;
    }
};
