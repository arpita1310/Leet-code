class Codec {
public:
    string serialize(TreeNode* root) {
         if(!root)
            return "null,";
      string s=to_string(root->val)+",";
      string s1=serialize(root->left);
      string s2=serialize(root->right);
      return s+s1+s2;
    }  
    TreeNode* makeTree(queue<string> & q)
    {
        string s=q.front();
        q.pop();
        if(s=="null")
            return NULL;
        TreeNode* t=new TreeNode(stoi(s));
        t->left=makeTree(q);
        t->right=makeTree(q);
        return t;
        
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s="";
        for(char c:data)
        {
            if(c==',')
            {
                q.push(s);
                s="";
            }
            else
                s+=c;
        }
        return makeTree(q);
    }
};