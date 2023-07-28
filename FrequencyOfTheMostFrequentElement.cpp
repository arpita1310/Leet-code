class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        long long currSum = 0;
        int res = 0, start = 0, end = 0;
        while(end < nums.size()){
            currSum += nums[end];
            while(nums[end] > (currSum+k)/(end-start+1)){
                currSum -= nums[start];
                start++;
            }    
            res = max(res, end-start+1);
            end++;
        }
        return (int) res;
    }
};