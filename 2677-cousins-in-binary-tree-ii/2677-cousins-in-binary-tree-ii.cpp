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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> ls;
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            if(a==NULL){
                ls.push_back(sum);
                sum=0;
                if(!q.empty())q.push(NULL);
            }else{
                sum+=a->val;
                if(a->left) q.push(a->left);
                if(a->right)q.push(a->right);
            }
        }
        int i=1;
        q.push(root);
        q.push(NULL);
        int cs=ls[i++];
        root->val=0;
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            if(a==NULL){
                if(!q.empty()){
                    if(i<ls.size())cs=ls[i++];
                    q.push(NULL);
                }
            }else{
                int req=0;
                if(a->left) {
                    req+=a->left->val;
                    q.push(a->left);
                }
                if(a->right){
                    req+=a->right->val;
                    q.push(a->right);
                }
                if(a->left)a->left->val=cs-req;
                if(a->right)a->right->val=cs-req;
            }
        }
        return root;
    }
};