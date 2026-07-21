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
    int helper(TreeNode* root, bool &d){
        if(!root){
            return 0;
        }
        if(!d){
            return 0;
        }
        int l = helper(root->left,d);
        int r = helper(root->right,d);

        if(abs(l-r)>1){
            d = false;
            return 0;
        }
        return max(l,r)+1;

    }
    bool isBalanced(TreeNode* root) {
        bool d = true;
        helper(root,d);
        return d;
    }
};
