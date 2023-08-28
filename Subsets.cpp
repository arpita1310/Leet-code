class Solution {
public:
    void helper(int j,vector<vector<int>>&ans, vector<int>&temp, vector<int>&nums){
        if(j==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[j]);
        helper(j+1,ans,temp,nums);
        temp.pop_back();
        helper(j+1,ans,temp,nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,ans,temp,nums);
        return ans;
    }
};