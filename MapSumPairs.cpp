class MapSum
{
unordered_map<string,int>mp;
public:
MapSum() {}

void insert(string key, int val) {
    mp[key]=val;
}

int sum(string prefix) {

    int ans=0;
    for(auto x:mp){
        size_t found = x.first.find(prefix);
       if (found != string::npos && found==0) 
	   {
           ans+=x.second;
       }
    }

    return ans;
}
};