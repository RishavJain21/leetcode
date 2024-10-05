class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n%2==1) return (long long)-1;
        sort(skill.begin(),skill.end());
        int ts=skill[0]+skill[n-1];
        long long chem=0;

        for(int i=0;i<n/2;i++){
            int s=skill[i]+skill[n-i-1];
            if(s!=ts) return -1;
            else{
                chem+= (long long)(skill[i]*skill[n-i-1]);
            }
        }
        return chem;
    }
};