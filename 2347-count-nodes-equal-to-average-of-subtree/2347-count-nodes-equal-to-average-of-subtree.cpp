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

    int ans;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return{0,0};
        pair<int,int> a=solve(root->left);
        pair<int,int> b=solve(root->right);
        pair<int,int> c;
        c.first=a.first+b.first+root->val;
        c.second=a.second+b.second+1;
        if(c.first/c.second==root->val) ans++;
        // cout<<root->val<<" "<<c.first<<" "<<c.second<<" "<<ans<<endl;
        return c ;
    }

    int averageOfSubtree(TreeNode* root) {
        int sum=0,n=0;
        solve(root);
        return ans;
    }
};