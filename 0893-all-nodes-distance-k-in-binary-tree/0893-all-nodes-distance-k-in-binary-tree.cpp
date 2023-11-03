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
    unordered_map<int,TreeNode*> par;
    unordered_map<int,int> vis;
    vector<int> ans;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            par[root->left->val]=root;
            dfs(root->left);
        }
        if(root->right){
            par[root->right->val]=root;
            dfs(root->right);
        }
    }
    void dfs1(TreeNode* root,int k){
        if(root==NULL) return;
        vis[root->val]=1;
        if(k==0) {
            ans.push_back(root->val);
            return;
        }
        if(root->left && !vis[root->left->val]) dfs1(root->left,k-1);
        if(root->right && !vis[root->right->val]) dfs1(root->right,k-1);
    }
    void dfs2(TreeNode* root,int k){
        if(root==NULL) return;
        vis[root->val]=1;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(par[root->val] && !vis[par[root->val]->val]) dfs2(par[root->val],k-1);
        if(root->left && !vis[root->left->val]) dfs1(root->left,k-1);
        if(root->right && !vis[root->right->val]) dfs1(root->right,k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        dfs(root);
        dfs1(target,k);
        dfs2(target,k);
        return ans;
    }
};