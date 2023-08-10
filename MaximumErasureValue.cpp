class Solution {
    
    /*
        Time Complexity : O(N)
        Space Complexity : O(N)
    */
    
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0, currSum = 0;
        int start = 0, end = 0;
        map<int, int> m1;
        
        while(end < nums.size()){
            m1[nums[end]]++;
            currSum += nums[end];
            
            while(m1[nums[end]] > 1){
                currSum -= nums[start];
                m1[nums[start]]--;
                start++;
            }
            
            maxSum = max(maxSum, currSum);
            end++;
        }
        
        return maxSum;
    }
};