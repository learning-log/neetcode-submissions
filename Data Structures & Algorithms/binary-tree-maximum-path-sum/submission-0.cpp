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
    int helper(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }

        int l = helper(root->left,ans);
        int r = helper(root->right,ans);

        int temp_ans = max(max(l+r+root->val,root->val),l+root->val);
        temp_ans = max(temp_ans,root->val+r);

        ans = max(temp_ans, ans);

        return max(max(root->val,l+root->val),r+root->val);



    }
    int maxPathSum(TreeNode* root) {
        int ans = -9999999;
        helper(root,ans);
        return ans;
    }
};
