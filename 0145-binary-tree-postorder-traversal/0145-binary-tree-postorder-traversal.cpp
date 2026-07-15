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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> an;
        op(an, root);
        return an;
    }
    
    void op(vector<int>& an, TreeNode* root){
            if (root == nullptr)
            return;

        
        op(an, root->left);
        op(an, root->right);
        
        an.push_back(root->val);
    }
};