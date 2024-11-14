class Solution {
public:
    bool solve(int n,vector<int>& q,int a){
        int i=0,k=0;
        for(int i=0;i<q.size();i++){
            k= k+ceil(q[i]/(float)a);
        }
        return k<=n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int i=1,j=100000,mid,ans=100000;
        while(i<=j){
            mid=i+(j-i)/2;
            if(solve(n,q,mid)){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};