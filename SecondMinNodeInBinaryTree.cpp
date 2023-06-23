class Solution {
public:
    void push(TreeNode* root, vector<int> & v){
        if(!root){
            return;
        }
        push(root->left,v);
        v.push_back(root->val);
        push(root->right,v);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> ans;
        push(root,ans);
        sort(ans.begin(),ans.end());
        int mini = ans[0];
        int n = ans.size();
        if(ans[0]==ans[n-1]){
            return -1;
        }
        for(int i = 0 ; i<n ; i++){
            if(mini<ans[i]){
                mini = ans[i];
                break;
            }
        }
        return mini;
    }
};