class Solution {
public:
    bool solve(int i, vector<int>&arr, int n,vector<int> &dp){
        if(i>=arr.size()) return true;
        if(dp[i]!=-1) return dp[i];
        bool ans = false;
        if(i+1<n && arr[i] == arr[i+1]){
            ans |= solve(i+2,arr,n,dp);
        }
        if(i+2<n && ((arr[i] == arr[i+1] && arr[i+1] == arr[i+2]) || (arr[i]+1 == arr[i+1] && arr[i+1]+1 == arr[i+2])) ){
            ans |= solve(i+3,arr,n,dp);
        }
        return dp[i] = ans;
    }
    bool validPartition(vector<int>& arr) { 
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(0,arr,n,dp);
    }
};