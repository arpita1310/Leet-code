class Solution {
public:
    int f(vector<int>&nums){
       int n=nums.size();
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
        {
           int curr=max(prev1,prev2+nums[i]);
           prev2=prev1;
           prev1=curr;
        }
        return prev1; 
    }
    int rob(vector<int>& nums) {
       vector<int>temp1,temp2;
       int n=nums.size();
       if(n==1)
         return nums[0];
        if(n==2)
         return max(nums[0],nums[1]);
       for(int i=0;i<n;i++){
           if(i!=0)  temp1.push_back(nums[i]);
           if(i!=n-1)     temp2.push_back(nums[i]);
       }
       return max(f(temp1),f(temp2));
    }
};