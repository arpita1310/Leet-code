class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,1));
        int top=0, left=0, right=n-1, bottom=n-1, k=1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
            ans[top][i]=k;
            k++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans[i][right]=k;
                k++;
            }
            right--;
            for(int i=right;i>=left;i--){
                ans[bottom][i]=k;
                k++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                ans[i][left]=k;
                k++;
            }
            left++;
        }
       return ans;
    }
};