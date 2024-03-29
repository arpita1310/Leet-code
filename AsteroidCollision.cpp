class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>s;
        for(int i=0;i<ast.size();i++){
            if(s.empty() || ast[i]>0){
                s.push(ast[i]);
            }
            else{
                while(!s.empty() and s.top()>0 and s.top()<abs(ast[i]) ){
                    s.pop();
                }
                if(!s.empty() and s.top()==abs(ast[i]) ){
                    s.pop();
                }
                else{
                    if(s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }
        vector<int>ans(s.size());
        for(int i=s.size()-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};