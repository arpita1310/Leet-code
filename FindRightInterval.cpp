class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>v;
        map<int,int>mp;
        int id = 0;
        for(auto i:intervals){
            v.push_back(i[0]);
            mp[i[0]] = id;
            id++;
        }
        sort(v.begin(),v.end());
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            auto it = lower_bound(v.begin(),v.end(),end);
            if(it == v.end()){
                ans[mp[start]] = -1;
                continue;
            }
            int idx = it - v.begin();
            ans[mp[start]] = mp[v[idx]];
        }
        return ans;
    }
};