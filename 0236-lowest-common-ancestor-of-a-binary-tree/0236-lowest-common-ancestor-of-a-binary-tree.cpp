/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    
class Solution {
public:
    bool found =0;
    void dfs(TreeNode * root , TreeNode * p, vector<TreeNode*> & path)
    {
        if(!root) return;
        if(root==p){
            path.push_back(root);
            found=1;
            return;
        }
        dfs(root->left, p, path);
        if(found)
        {
            path.push_back(root);
            return;
        } 
        dfs(root->right, p , path);
        if(found)
        {
            path.push_back(root);
            return;
        } 
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath, qpath;
        
        dfs(root, p, ppath);
        found=0;
        dfs(root ,q, qpath);
        for(auto x:ppath) cout<<x->val<<" ";
        cout<<"\n";
        for(auto x:qpath) cout<<x->val<<" ";
        int i=ppath.size()-1;
        int j=qpath.size()-1;
        while(i>=0 and j>=0)
        {
            if(ppath[i]==qpath[j])
            {
                i--;
                j--;
            }
            else {
                break;
            }
        }
        if(i<0) return ppath[0];
        return ppath[i+1];
    }
};