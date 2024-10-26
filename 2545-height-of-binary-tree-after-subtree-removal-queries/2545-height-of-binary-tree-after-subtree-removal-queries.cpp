/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v2;
    int helper(TreeNode* root ){
        if(!root) return -1;
        int lh=helper(root->left);
        int rh=helper(root->right);
        int h=max(lh,rh)+1;
        return v2[root->val]=h;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> v1(1e5+1,0);
        v2.resize(1e5+1,-1);
        helper(root);
        queue<TreeNode*> q;
        v1[root->val]=0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            if(a==NULL){
                if(!q.empty()){
                    vector<TreeNode*> v;
                    int b=q.size();
                    int m=-1,m2=-1;
                    while(b--){
                        TreeNode* c=q.front();
                        v.push_back(c);
                        if(v2[c->val]>m) {m2=m;m=v2[c->val];}
                        else if(v2[c->val]>m2) m2=v2[c->val];
                        q.pop();
                        q.push(c);
                    }
                    int r=v2[root->val];
                    for(auto i:v){
                        if(m2==-1){
                            v1[i->val]=r-v2[i->val]-1;
                        }else{
                            if(v2[i->val]==m){
                                v1[i->val]=r-(m-m2);
                            }else{
                                v1[i->val]=r;
                            }
                        }
                    }
                    q.push(NULL);
                }
            }else{
                if(a->left) q.push(a->left);
                if(a->right)q.push(a->right);
            }
        }
        vector<int> ans;
        for(auto i:queries){
            ans.push_back(v1[i]);
        }
        return ans;
    }
};