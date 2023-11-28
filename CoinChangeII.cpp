class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n][amount+1];
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)  dp[0][i]=1;
            else dp[0][i]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int np=dp[i-1][j];
                int p=0;
                if(coins[i]<=j){
                    p=dp[i][j-coins[i]];
                }
                dp[i][j]=p+np;
            }
        }
        return dp[n-1][amount];
    }
};