/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

            if (root->val == key)
                return helper(root);

        TreeNode* curr = root;

        while (curr != NULL) {
            if (key < curr->val) {
                if (curr->left != NULL && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right != NULL && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL){
            return root->right;
        }
        if (root->right == NULL){
            return root->left;
        }

        TreeNode* leftChild = root->left;
        TreeNode* lastRight = findRightMost(leftChild);
        lastRight->right = root->right;
        return leftChild;
    }
    TreeNode* findRightMost(TreeNode* root) {
        while (root->right != NULL){
            root = root->right;
            }
        return root;
    }
};