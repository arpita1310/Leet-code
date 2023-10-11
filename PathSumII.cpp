class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int t,vector<int> v)
    {
        if(!root)
            return;
        v.push_back(root->val);
        if(root->val==t && !root->left && !root->right)
        {
            ans.push_back(v);
            return;
        }
        dfs(root->left, t-root->val,v);
        dfs(root->right, t-root->val,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        dfs(root, targetSum, v);
        return ans;
    }
};