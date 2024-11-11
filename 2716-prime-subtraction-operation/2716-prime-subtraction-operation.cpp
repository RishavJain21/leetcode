class Solution {
public:
    void get_prime(int n,vector<int>& prime){
        bitset<1001> b;
        b.set();
        b[0]=b[1]=0;
        for(int i=2;i<=n;i++){
            if(b[i]){
                for(int j=i*i;j<=n;j+=i){
                    b[j]=0;
                }
                prime.push_back(i);
            }
        }
    }
    int get_required_prime(int n,int m,vector<int>& p){
        int i=0,j=p.size()-1,ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(m-p[mid]<n){
                ans=m-p[mid];
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p;
        get_prime(1001,p);
        int t=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=t){
                int a=get_required_prime(t,nums[i],p);
                if(a<=0) return false;
                nums[i]=a;
            }
            t=nums[i];
        }
        return 1;
    }
};