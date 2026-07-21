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

class Codec {
public:

    // Encodes a tree to a single string.
    void serialize_helper(TreeNode* root,string &ans){
        if(!root){
            ans += "*#";
            return;
        }
        ans +="*"+to_string(root->val);
        serialize_helper(root->left,ans);
        // ans +="*"+to_string(root->val);
        serialize_helper(root->right,ans);

    }

    string serialize(TreeNode* root) {
        string ans = "";
        serialize_helper(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    int calVal(string data, int &posi){
        int ans = 0;
        while(posi<data.size() and data[posi]!='*'){
            ans = (ans*10+(data[posi]-'0'));
            posi= posi+1;
        }
        posi= posi+1;
        return ans;
    }
    TreeNode* deserialize_helper(string data,int &posi){
        if(posi==data.size()){
            return nullptr;
        }
        if(data[posi]=='#'){
            posi= posi+2;
            return nullptr;
        }
        int val = calVal(data, posi);
        TreeNode* node = new TreeNode(val);

        TreeNode* l = deserialize_helper(data,posi);
        TreeNode* r = deserialize_helper(data,posi);

        node->left = l;
        node->right = r;
        return node;

    }
    TreeNode* deserialize(string data) {
        int posi = 1;
        cout<<data<<endl;
        // TreeNode* node = new TreeNode(9);
        TreeNode* node = deserialize_helper(data,posi);
        return node;
    }
};
