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
    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& result, set<int>& st) {
        if (!root) return NULL;

        root->left = dfs(root->left, result, st);
        root->right = dfs(root->right, result, st);

        if (st.find(root->val) != st.end()) {
            if (root->left) result.push_back(root->left);  
            if (root->right) result.push_back(root->right);  
            return NULL;  
        }

        return root;  
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;

        if (dfs(root, result, st) != NULL) {
            result.push_back(root);
        }

        return result;
    }
};
