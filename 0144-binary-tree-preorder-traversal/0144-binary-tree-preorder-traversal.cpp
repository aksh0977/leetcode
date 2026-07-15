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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> an;
        preorder(an, root);
        return an;
    }

    void preorder(vector<int>& an, TreeNode* root){
        if(root == nullptr){
            return;
        }

        an.push_back(root->val);
        preorder(an, root->left);
        preorder(an, root->right);
    }
};