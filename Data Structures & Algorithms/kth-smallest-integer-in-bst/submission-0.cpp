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
    int kthSmallest(TreeNode* root, int &k) {
        if(!root){
            return -1;
        }
        int l = kthSmallest(root->left,k);
        k--;
        if(k==0){
            return root->val;
        }
        if(l!=-1){
            return l;
        }
        int r = kthSmallest(root->right,k);

        if(r!=-1){
            return r;
        }

    }
};
