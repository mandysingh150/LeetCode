class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        // add start as {start, 0}
        // add end as {end, 1}
    }
    
    bool book(int start, int end) {
        auto next = st.lower_bound({start, end}); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if(next != st.end() and end > next->first)
            return 0;
        if(next != st.begin() and start < (--next)->second)
            return 0;
        st.insert({start, end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */