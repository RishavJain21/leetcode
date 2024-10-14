class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;

        for(auto i: nums) pq.push(i);
        while(k--){
            int a =pq.top();
            pq.pop();
            ans+=(long long)a;
            pq.push(ceil(a/3.0));
        }
        return ans;
    }
};