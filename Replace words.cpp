class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        map<string,int>m;
        for(int i=0;i<d.size();++i){
            m[d[i]]=1;
        }
        string ans=""; 
        for(int i=0;i<s.size();++i){
            int k=i;
            string temp="";
            while(i<s.size() && s[i]!=' '){ 
                temp+=s[i];
                if(m[temp]==1){
                    break;
                }
                i++;
            }
            
            if(s[i]!=' '){
                while(i<s.size() && s[i]!=' ')
                    i++;
                
            }

            if(ans.size()>0)
                ans+=" "+temp;
            else
                ans+=temp;

        }
        return ans;
    }
};