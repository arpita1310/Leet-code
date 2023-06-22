class Solution {
    int xlvl=0,ylvl=0;
    TreeNode *xparent=NULL,*yparent=NULL;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y);
        return xlvl==ylvl && xparent!=yparent;
    }
    void dfs(TreeNode* root, int x, int y,int lvl=0,TreeNode* parent=NULL) {
        if(!root)return;
        if(root->val==x){
            xlvl=lvl;
            xparent=parent;
        }
        if(root->val==y){
            ylvl=lvl;
            yparent=parent;
        }
        dfs(root->left,x,y,lvl+1,parent=root);
        dfs(root->right,x,y,lvl+1,parent=root);
    }
};