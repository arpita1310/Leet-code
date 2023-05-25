class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) 
            return false;

        if(s.size()==1 and goal.size()==1 and s==goal) 
            return false;

        set<char> st;
        if(s==goal){
            for(auto i: s) st.insert(i);
        }

        if(s.size()>2 and s.size()==st.size()) 
            return false;

        unordered_map<char, int> mp;
        for(auto i: goal) mp[i]++;

        for(auto i: s){
            if(mp[i]==0)
                return false;

            mp[i]--;    
        }

        int i=0, count=0;
        while(i<s.size() and s.size() >2){
            if(s[i] != goal[i])
                count++;

            if(count>2)
                return false;

            i++;     
        }

        if(s.size()==2){
            swap(s[1], s[0]);

            if(s==goal) return true;
            else return false;
        }

        return true;
    }
};