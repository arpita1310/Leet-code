class MyCalendarTwo {
    map<int,int>mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto& it:mp){
            sum+=it.second;
            if(sum>=3){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};