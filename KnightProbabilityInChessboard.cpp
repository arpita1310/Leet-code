class Solution {
public:
double dp[26][26][101];
     double knightProbability(int n, int k, int row, int column) {
        return help(n,k,row,column);
    }

    double help(int n, int k, int r, int c){
         if(r<0 || r>=n || c<0  || c>=n){
            return 0;
        }
        if(k==0)  return 1;
        if(dp[r][c][k]){
            return dp[r][c][k];
        }
        double sum=0;
        sum = help(n, k-1, r-2, c-1) + help(n, k-1, r-1, c-2) + 
            help(n, k-1, r+2, c+1) + help(n, k-1, r+1, c+2)+ 
            help(n, k-1, r-2, c+1)+ help(n, k-1, r+2, c-1) +
            help(n, k-1, r-1, c+2) + help(n, k-1, r+1, c-2);
        sum/=8.0;
        return dp[r][c][k]=sum;
    }
};