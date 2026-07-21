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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q and !p){
            return true;
        }
        else if(!p or !q){
            return false;
        }

        if(p->val!=q->val){
            return false;
        }
        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right, q->right);
        if(l and r)
        return true;

        return false;

    }
    void helper(TreeNode* root, TreeNode* subRoot,bool &ans){
        if(!root){
            return;
        }
        if(ans){
            return;
        }

        if(isSameTree(root,subRoot)){
            ans = true;
        }
        else{
            helper(root->left,subRoot,ans);
            helper(root->right,subRoot,ans);
        }
        return ;


    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        helper(root,subRoot,ans);
        return ans;
    }
};
