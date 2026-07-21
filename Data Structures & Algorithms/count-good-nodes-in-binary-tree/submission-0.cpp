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
    void helper(TreeNode* root,int curr,int &ans){
        if(!root){
            return;
        }
        if(root->val>=curr){
            ans++;
            curr = root->val;
        }
        helper(root->left,curr,ans);
        helper(root->right,curr, ans);
        return;
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int curr = -101;
        helper(root,curr,ans);
        return ans;
    }
};
