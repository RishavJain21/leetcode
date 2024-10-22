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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans=0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long long sum=0;
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            if(a==NULL){
                if(pq.size()<k)pq.push(sum);
                else if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
                sum=0;
                if(!q.empty()) q.push(NULL);
            }else{
                sum+=a->val;
                if(a->left) q.push(a->left);
                if(a->right)q.push(a->right);
            }
        }
        return pq.size()==k?pq.top():-1;
    }
};