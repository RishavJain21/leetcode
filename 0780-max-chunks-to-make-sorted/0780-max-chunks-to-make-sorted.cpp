class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int a=0,b=0;

        for(int i=0;i<arr.size();i++){
            a+=i;
            b+=arr[i];
            if(a==b) ans++;
        }
        return ans;
    }
};