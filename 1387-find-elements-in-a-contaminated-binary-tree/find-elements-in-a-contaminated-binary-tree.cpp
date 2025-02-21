class FindElements {
public:
    unordered_set<int> st;

    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    void dfs(TreeNode* node, int val) {
        if (!node) return;
        st.insert(val);
        dfs(node->left, 2 * val + 1);
        dfs(node->right, 2 * val + 2);
    }

    inline bool find(int target) {
        return st.count(target);
    }
};
