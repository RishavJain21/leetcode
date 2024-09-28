class MyCircularDeque {
public:
    vector<int> v;
    int f,r,s,c;
    MyCircularDeque(int k) {
        v.resize(k,-1);
        f=0;r=k-1;c=k;s=0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return 0;
        f=(f-1+c)%c;
        v[f]=value;
        s++;
        return 1;
    }
    
    bool insertLast(int value) {
        if(isFull()) return 0;
        r=(r+1)%c;
        v[r]=value;
        s++;
        return 1;
    }
    
    bool deleteFront() {
        if(isEmpty()) return 0;
        f=(f+1)%c;
        s--;
        return 1;
    }
    
    bool deleteLast() {
        if(isEmpty()) return 0;
        r=(r-1+c)%c;
        s--;
        return 1;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return v[f];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return v[r];
    }
    
    bool isEmpty() {
        return s==0;
    }
    
    bool isFull() {
        return s==c;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */