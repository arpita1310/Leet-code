class Solution 
{
public:
    map<pair<int,int>,double> m;
    double f(int i, vector<int> &nums, int k)
    {
        int n=nums.size();
        if(i!=n && k==0) return INT_MIN;
        if(i==n || k<=0) return 0;
        if(m.find({i,k})!=m.end()) return m[{i,k}];
        double sum=0, count=0, ans=0;
        for(int x=i; x<=n-k; x++)
        {
            count++;
            sum+=nums[x];
            ans=max(ans,sum/count+f(x+1,nums,k-1));
        }
        return m[{i,k}]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        double mx=0;
        for(int x=1; x<=k; x++)
        {
            mx=max(mx,f(0,nums,x));
        }
        return mx;
    }
};