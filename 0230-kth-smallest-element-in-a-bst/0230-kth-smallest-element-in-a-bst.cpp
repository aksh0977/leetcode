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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        TreeNode* op = root;
        stack<TreeNode*> st;
        
        while (!st.empty() || op!=NULL) {
            while(op){
                st.push(op);
                op = op->left;
            }
            op = st.top();
            st.pop();

            ans.push_back(op->val);
            
            op=op->right;
        }

        return ans[k-1];
    }
};