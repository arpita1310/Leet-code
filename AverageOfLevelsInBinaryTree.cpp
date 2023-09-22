class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        double sum;
        q.push(root);
        while(!q.empty()){
            sum=0;
            int size =q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                if(curr->left!=NULL) {q.push(curr->left);}
                if(curr->right!=NULL) {q.push(curr->right);}
                sum+=curr->val;
                q.pop();
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};