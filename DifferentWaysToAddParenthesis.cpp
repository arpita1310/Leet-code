class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        unordered_map <string, vector<int>>dp;

        for(int indx=0;indx<expression.length();indx++){

            char curr= expression[indx];
            if(curr=='*' || curr == '+' || curr== '-'|| curr=='/'){
                vector<int>left,right;
                string str1= expression.substr(0,indx);
                string str2= expression.substr(indx+1);
                if(dp.find(str1)!=dp.end())
                    left=dp[str1];
                else
                    left=diffWaysToCompute(str1);
                
                if(dp.find(str2)!=dp.end())
                    right=dp[str2];
                else
                    right=diffWaysToCompute(str2);

                for(int i:left){
                for(int j:right){
                    if(curr=='+') ans.push_back(i+j);
                    if(curr=='-') ans.push_back(i-j);
                    if(curr=='*') ans.push_back(i*j);
                    if(curr=='/') ans.push_back(i/j);
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(expression));
        } 
        return ans;
    }
};