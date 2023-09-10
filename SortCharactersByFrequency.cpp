class Solution {
public:
    static bool cmp(pair<char,int>&a, pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>>res;
        for(auto it:mp){
            res.push_back(it);
        }
        sort(res.begin(),res.end(),cmp);
        string ans="";
        for(auto it:res){
            int tmp=it.second;
            while(tmp--){
                ans+=it.first;
            }   
        }
        return ans;
    }
};
