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

//basic concept : for every node ans will be LevelSum - SiblingSum
class Solution {
public:
    // void dfs(TreeNode*root,int level, int sibSum,vector<long long>sums){
    //     if(root==NULL)return;
    //     if(level==0){
    //         root->val=0;
    //     }
    //     else {
    //         root->val = sums[level] - sibSum;
    //     }
    //     int a=0,b=0;
    //     if(root->left!=NULL) a = root->left->val;
    //     if(root->right!=NULL) b = root->right->val;
    //     dfs(root->left,level+1,a+b,sums);
    //     dfs(root->right,level+1,a+b,sums);
    // }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long>sums;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            long long sum=0;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();q.pop();
                sum+=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }

                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            sums.push_back(sum);
        }

        // dfs(root,0,0,sums);
        q.push(root);
        root->val=0;
        int level=1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();q.pop();

                int sibSum = node->left!=NULL ? node->left->val:0;
                sibSum+=node->right!=NULL ? node->right->val:0;
                
                if(node->left){
                    node->left->val = sums[level] - sibSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = sums[level] - sibSum;
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};