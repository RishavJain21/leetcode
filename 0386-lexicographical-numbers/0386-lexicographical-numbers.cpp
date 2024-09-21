class Solution {
public:
    void solve(int k,int n,vector<int>& ans){
        if(k>n) return;
        ans.push_back(k);
        for(int i=0;i<=9;i++){
            int temp=k*10+i;
            if(temp<=n) solve(temp,n,ans);
            else break;
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        // for(int i=1;i<=9;i++)solve(i,n,ans);
        int num=1;
        for(int i=0;i<n;i++){
            ans.push_back(num);
            if(num*10<=n) num*=10;
            else{
                while(num%10==9 || num>=n) num/=10;
                num+=1;
            }
        }

        return ans;
    }
};