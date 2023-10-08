class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
       unordered_map<string,int>mp;
        string temp;
        for(int i=0;i<emails.size();i++){
            temp=" ";
            auto pos=emails[i].find('@');
            string p2=emails[i].substr(pos);
            string p1=emails[i].substr(0,pos);
            p1.erase(remove(p1.begin(),p1.end(),'.'),p1.end());
            pos=p1.find('+');
           if(pos!=string::npos){
               p1=p1.substr(0,pos);
           }
            mp[p1+p2]=0;
        }
        return mp.size();
    }
};