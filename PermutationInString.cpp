class Solution {
public:
    bool checkInclusion(string s1, string s2){
        vector<int> count(26,0), ans(26,0);
        for(int i=0; i<s1.length(); i++)
            count[s1[i]-'a']++;
        int i=0, j=0;
        while(j<s2.length()){
            if((j-i)<s1.length()){ 
                ans[s2[j]-'a']++; 
                j++;
            }
            else{
                ans[s2[i]-'a']--; 
                i++;
            }
            if(ans == count)
                return true;
        }
        return false;
    }
};