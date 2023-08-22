class Solution {
public:
    int dp[9]={1};
    int solve(int n){
        if(n==0|| dp[n]!=0)   return dp[n];
        int ans=9,temp=9;
        for(int i=1;i<n;i++){
            ans*=temp--;
        }
        return dp[n]=ans+solve(n-1);
    }
    int countNumbersWithUniqueDigits(int n) {
        return solve(n);
    }
};