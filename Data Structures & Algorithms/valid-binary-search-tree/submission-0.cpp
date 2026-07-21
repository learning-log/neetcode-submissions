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
    void helper(TreeNode* root, int mi, int ma,bool &ans){
        if(!root){
            return;
        }
        if(root->val>=ma or root->val<=mi){
            ans = false;
            return;
        }
        helper(root->left,mi,root->val,ans);
        helper(root->right,root->val,ma,ans);
    }
    bool isValidBST(TreeNode* root) {
        int mi = -1001;
        int ma = 1001;
        bool ans = true;
        helper(root,mi,ma,ans);
        return ans;
        
    }
};
