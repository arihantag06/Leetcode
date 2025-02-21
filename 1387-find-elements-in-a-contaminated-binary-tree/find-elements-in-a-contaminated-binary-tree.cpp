class FindElements {
public:
    unordered_set<int> st;
    
    void dfs(TreeNode* node, int val) {
        st.insert(val);
        if (node->left) dfs(node->left, 2 * val + 1);
        if (node->right) dfs(node->right, 2 * val + 2);
    }

    FindElements(TreeNode* root) {
        if (root) dfs(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};
