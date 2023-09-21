class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sa=0,sb=0;
        for(int i:aliceSizes)
            sa+=i;
        for(int j:bobSizes)
            sb+=j;
        int delta = (sb-sa)/2;
        vector<int>ans;
    for(int i:aliceSizes){
        if(find(bobSizes.begin(),bobSizes.end(),i+delta)!=bobSizes.end()){
            ans.push_back(i);
            ans.push_back(i+delta);
            break;
        }
    }
           return ans;
    }
};