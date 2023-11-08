class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1) return 0;
        int a=min(abs(fx-sx),abs(fy-sy));
        a+=abs(fx-sx)+abs(fy-sy)-2*a;
        return a<=t;
    }
};