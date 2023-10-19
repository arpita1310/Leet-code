class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(candyType[i]);
        }
        n/=2;
        if(s.size()<n){
            return s.size();
        }
        return n;
    }
};