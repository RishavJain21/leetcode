class Solution {
public:
    int solve(vector<int>& b, int m, int k){
        int a=0,c=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=m) c++;
            else c=0;
            if(c==k){
                a++;c=0;
            }
        }
        return a;
    }
    int minDays(vector<int>& b, int m, int k) {
        int l=0,h=0;
        for(auto i:b) h=max(h,i);
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;

            if(solve(b,mid,k)>=m){
                ans=mid;
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};