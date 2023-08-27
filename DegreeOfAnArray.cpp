class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int temp=0,n=nums.size();
        for(auto &i:nums){
            mp[i]++;
            if(mp[i]>temp) 
                temp=mp[i]; 
        }
        if(temp==1)
            return 1;
        int ans=INT_MAX;
        for(auto &i:mp){
            if(i.second == temp){
                int l=0,r=n-1;
                while(l<=r && nums[l]!=i.first) 
                    l++;
                while(l<=r && nums[r]!=i.first) 
                    r--;
                ans=min(ans,r-l+1);            
            }
        }        
        return ans;
    }
};