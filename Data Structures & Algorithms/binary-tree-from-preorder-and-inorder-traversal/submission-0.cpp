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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int s, int end, int &posi){
        if(end<s){
            return nullptr;
        }
        // if(end==s){
        //     return 
        // }

        TreeNode* node = new TreeNode(preorder[posi]);
        // posi++;
        int i=s;
        for(;i<=end;i++){
            if(preorder[posi]==inorder[i]){
                break;
            }
        }
        posi++;
        node->left = helper(preorder,inorder,s,i-1,posi);
        node->right = helper(preorder,inorder,i+1,end,posi);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int posi = 0;
        int s = 0;
        int end = inorder.size()-1;
        return helper(preorder, inorder,s,end,posi);
    }
};
