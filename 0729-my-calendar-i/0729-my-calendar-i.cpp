class MyCalendar {
public:
    set<pair<int,int>> st;
    
    bool book(int start, int end) {
        pair<int,int> b=make_pair(start,end);
        auto a=st.lower_bound(b);
        if(a!=st.end() && a->first<end) return 0;
        if(a!=st.begin()){
            a=prev(a);
            if(a->second>start) return 0;
        }
        st.insert(b);
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */