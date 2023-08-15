class Solution {
public:
    void combinationSum3(int n, int k, vector<vector<int>> &output, vector<int> &temp, int start, int sum){
        if(temp.size() == k){
            if(n == sum){
                output.push_back(temp);
            }
            return;
        }
        for(int i=start; i<=9; i++){
            temp.push_back(i); 
            combinationSum3(n, k, output, temp, i+1, sum+i);
            temp.pop_back(); 
        }
    }     
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum3(n, k, output, temp, 1, 0);
        return output;
    }
};