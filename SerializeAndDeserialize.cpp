class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr==NULL){
                ans.append("#,");
            }
            else{
                ans.append(to_string(curr->val)+",");
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)  return NULL;
        stringstream s(data);  //convert string into object
        string str;   
        getline(s,str,',');        //this will separate string(s, converted to object) on the basis of ", " and store in str
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                curr->left=NULL;
            }
            else{
                TreeNode* leftNode= new TreeNode(stoi(str));
                curr->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str=="#"){
                curr->right=NULL;
            }
            else{
                TreeNode* rightNode= new TreeNode(stoi(str));
                curr->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};