struct node {
    bool eow = false;
    node* a[26] = {nullptr};
};
class StreamChecker {
public:
    node* root;
    StreamChecker(vector<string>& words) {
        root = new node;
        for(auto& val: words) {
            reverse(val.begin(), val.end());
            node* temp = root;
            for(int i = 0; i < val.size(); ++i) {
                int ind = val[i] - 'a';
                if(temp -> a[ind] == nullptr) temp -> a[ind] = new node;

                temp = temp -> a[ind];
            }
            temp -> eow = true;
        }
    }
    deque<char> dq;
    bool query(char letter) {
        if(dq.size() == 200) dq.pop_front();
        dq.push_back(letter);
        node* temp = root;
        for(int i = dq.size() - 1; i >= 0; --i) {
            int ind = dq[i] - 'a';
            if(temp -> a[ind] == nullptr) {
                return false;
            }
            else temp = temp -> a[ind];
            if(temp -> eow) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
