class Solution {
public:
    string longestWord(vector<string>& a) {
        sort(a.begin(), a.end());
         map<string, int>mp;

             mp[""]++;
             string ans;

          for(auto i:a){
              
              string temp=i.substr(0,i.size()-1);

              if(mp[temp]!=0){
                  if(ans.size()<i.size()){
                      ans=i;
                  }
                  mp[i]++;
              }
          }
return ans;
    }
};