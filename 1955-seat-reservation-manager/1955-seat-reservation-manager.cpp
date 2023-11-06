class SeatManager {
public:
    set<int> s;
    int i;
    SeatManager(int n) {
        i=1;
    }
    
    int reserve() {
        if(!s.empty()){
            int a=*s.begin();
            s.erase(a);
            return a;
        }
        return i++;
    }
    
    void unreserve(int j) {
        s.insert(j);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */