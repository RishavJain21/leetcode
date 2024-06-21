class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int n=c.size();
        int a=0,sum=0;
        for(int i=0;i<n;i++){
            if(g[i]==0) a+=c[i];
            sum+=c[i];
        }
        if(m>=n) return sum;
        int i=0,j=m-1,ans=a;
        while(j<n){
            int temp=0;
            for(int k=i;k<=j;k++){
                if(g[k]==1) temp+=c[k];
            }
            ans=max(ans,a+temp);
            i++;j++;
        }
        return ans;
    }
};