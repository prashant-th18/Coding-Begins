class MyCalendar {
public:
    vector<int> s, e;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto in1 = lower_bound(all(s), start) - begin(s);
        if(in1 == sz(s) || s[in1] <= end) return false;
        in1 = lower_bound(all(e), start) - begin(e);
        if(in1 == sz(e) || e[in1] <= end) return false;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
