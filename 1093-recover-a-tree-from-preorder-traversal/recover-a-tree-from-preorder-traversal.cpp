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
    TreeNode* recoverFromPreorder(string s) {
        vector<TreeNode*>parent(1001);
        int c = 0;
        TreeNode* res;
        int n = s.length();
        int i=0;
        while(i<n){
            if(s[i]=='-'){
                c++;
                i++;
            }
            else{
                string t;
                while(i<n && s[i]!='-'){
                    t+=s[i];
                    i++;
                }
                TreeNode*x=new TreeNode(stoi(t));
                parent[c+1]=x;
                if(c==0){
                    res=x;
                }
                else if(parent[c]->left==NULL){
                    parent[c]->left=x;
                }
                else {
                    parent[c]->right=x;
                }
                c=0;
            }
        }
        return res;
    }
};