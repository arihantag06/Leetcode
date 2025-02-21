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
class FindElements {
public:
    set<int>st;
    void dfs(TreeNode*node,int val){
        if(node==NULL)return;
        if(node->left){
            dfs(node->left,2*val+1);
            st.insert(2*val+1);
        }
        if(node->right){
            dfs(node->right,2*val+2);
            st.insert(2*val+2);
        }
    }
    FindElements(TreeNode* root) {
        if(root!=NULL){
            dfs(root,0);
            st.insert(0);
        }
    }
    
    bool find(int target) {
        if(st.find(target)!=st.end())return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */