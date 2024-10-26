class Solution {
public:
    int level[100001]; 
    int height[100001];
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];

    int findHeight(TreeNode* root,int lvl){
        if(!root){
            return 0;
        }
        level[root->val] = lvl;
        height[root->val] = max(findHeight(root->left,lvl+1),findHeight(root->right,lvl+1))+1;
        
        if(levelMaxHt[lvl]<height[root->val]){
            levelSecondMaxHt[lvl] = levelMaxHt[lvl];
            levelMaxHt[lvl] = height[root->val];
        } else if(levelSecondMaxHt[lvl]<height[root->val]){
            levelSecondMaxHt[lvl] = height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root,0);
        vector<int>result;
        for(int &node:queries){
            int L = level[node];
            int H = (levelMaxHt[L]==height[node])?levelSecondMaxHt[L]:levelMaxHt[L];
            int res = L+H-1;
            result.push_back(res);
        }
        return result;
    }
};