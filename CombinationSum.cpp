class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>ans={};
        vector<int> v;
        comb(0,nums,v,ans,target);
        return ans;
    }
    void comb(int start,vector<int>& nums,vector<int>& v,vector<vector<int>>&ans,int target)
    {
        if(target==0)
        ans.push_back(v);
        if(target<0)
        return;
        for(int i=start;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            comb(i,nums,v,ans,target-nums[i]);
            v.pop_back();
        }
    }
};