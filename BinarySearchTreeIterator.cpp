class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        forAll(root);
    }
    
    int next() {
        TreeNode* curr= s.top();
        s.pop();
        forAll(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }

    void forAll(TreeNode* node){
        for(;node!=NULL;node=node->left){
            s.push(node);
        }
    }
};