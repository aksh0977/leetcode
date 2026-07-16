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
    int ans = -1e9;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int left = op(root->left);
        int right = op(root->right);

        ans = max(ans, left+right);

        left>right ? diameterOfBinaryTree(root->left) :    
                        diameterOfBinaryTree(root->right);
        return ans;
    }

    int op(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1+max(op(root->left),op(root->right));
    }
};