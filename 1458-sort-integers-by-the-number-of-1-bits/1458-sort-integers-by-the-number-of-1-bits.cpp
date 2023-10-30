class Solution {
public:
    static int c1(int a){\
        int c=0;
        while(a){
            c+=a&1;
            a=a>>1;
        }
        return c;
    }
    static bool compare(int a,int b){
        int p=c1(a),q=c1(b);
        if(p==q) return a<=b;
        return p<q;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};