/**
 * Definition for a binary tree node->
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
          return helper(root,val);
    }
    TreeNode* helper(TreeNode* node, int val){
        if(node==NULL)return new TreeNode(val);
        if(node->val>val)node->left= helper(node->left,val);
        if(node->val<val)node->right= helper(node->right,val);
        return node;
    }
};