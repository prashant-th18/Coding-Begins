class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* temp = head, *less = nullptr, *more = nullptr, *mless = nullptr, *mhead = nullptr;
            while(temp) {
                if(temp -> val < x) {
                    if(less == nullptr) {
                        mless = temp;
                        less = temp;
                    }
                    else {
                        less -> next = temp;
                        less = less -> next;
                    }
                }
                else {
                    if(more == nullptr) {
                        mhead = temp;
                        more = temp;
                    }
                    else {
                        more -> next = temp;
                        more = more -> next;
                    }
                }
                temp = temp -> next;
            }
            if(mless == nullptr) {
                mless = mhead;
            }
            else {
                less -> next = mhead;
                if(more) more -> next = nullptr;
            }
            return mless;

        }
};
