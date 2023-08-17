class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int rindx=1;
        for(int i=2;i<n;i++){
            int current=nums[i];
            if(current==nums[rindx] && current==nums[rindx-1]){
                continue;
            }
            nums[++rindx]=nums[i];
        }
        return rindx+1;
    }
};