class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        set<int> st;

        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
            if(st.size()-1==*(st.rbegin())) ans++;
        }
        return ans;
    }
};