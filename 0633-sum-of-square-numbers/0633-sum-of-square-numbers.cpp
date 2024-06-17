class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0,j=sqrt(c);
        if(j==c) return 1;
        while(i<=j){
            long long a=i*i + j*j;
            if(a==c) return 1;
            else if(a<c) i++;
            else j--;
        }        
        return false;
    }
};