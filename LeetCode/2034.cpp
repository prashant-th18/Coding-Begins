class StockPrice {
public:
    set<pair<int, int>> st;
    multiset<int> mt;
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        set<pair<int, int>> :: iterator it = st.lower_bound({timestamp, 0});
        if(it == st.end() || (*it).first != timestamp) {
            st.insert({timestamp, price});
            mt.insert(price);
        }
        else {
            mt.erase(mt.find((*it).second));
            st.erase(it);
            mt.insert(price);
            st.insert({timestamp, price});
        }
    }
    
    int current() {
        return (*st.rbegin()).second;
    }
    
    int maximum() {
        return (*mt.rbegin());
    }
    
    int minimum() {
        return (*mt.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
