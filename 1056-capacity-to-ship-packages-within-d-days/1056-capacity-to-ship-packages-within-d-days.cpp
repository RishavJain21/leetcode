class Solution {
public:
    int solve(vector<int>& weights,int a){
        int c=0,d=0;
        for(int i=0;i<weights.size();i++){
            if(c+weights[i]>a){
                d++;
                c=0;
            }
            c+=weights[i];
        }
        if(c)d++;
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=2.5*1e7+1;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int a=solve(weights,mid);
            if(a<=days){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};