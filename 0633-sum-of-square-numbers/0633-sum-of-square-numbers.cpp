class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++){
            int l=i,h=sqrt(c);
            int a=c-pow(i,2);
            while(l<=h){
                int mid=l+(h-l)/2;
                int b=pow(mid,2);
                if(b==a) return true;
                else if(b>a){
                    h=mid-1;
                }else l=mid+1;
            }
        }
        return false;
    }
};