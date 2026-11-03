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
    int maxD=0;
    int diameterOfBinaryTree(TreeNode* root) {
        calcH(root);
        return maxD;
    }
    int calcH(TreeNode* root){
        if (root == NULL) return 0;
        int Leftheight =calcH(root->left);
        int rightheight =calcH(root->right);
        maxD=max(maxD,Leftheight+rightheight);
        return 1+max(Leftheight,rightheight);
         
    }
};