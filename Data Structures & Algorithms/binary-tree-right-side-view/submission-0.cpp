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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*>q;
        if(!root){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            // vector<int> temp;
            int st;
            for(int i=0;i<sz;i++){
                TreeNode* a = q.front();
                q.pop();
                // temp.push_back(a->val);
                st = a->val;
                if(a->left){
                    q.push(a->left);
                }
                if(a->right){
                    q.push(a->right);
                }
            }
            ans.push_back(st);
        }
        return ans;
    }
};
