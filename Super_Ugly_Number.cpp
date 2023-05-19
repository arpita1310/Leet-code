class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        if(n==1)
            return n;
        vector<int> dp(n+1,0);
        dp[1]=1;
        vector<int> lst(primes.size() , 1);
        for(int i=2 ; i<=n ; i++)
        {
            long long m = INT_MAX;
            for(int j=0 ; j<primes.size() ; j++)
            {
                long long ans = (long long)dp[lst[j]] * (long long)primes[j];
                m= min( m , ans);
            }
            dp[i]=m;
            
            for(int j=0 ; j<primes.size() ; j++)
                if( m == (long long)dp[lst[j]] * (long long)primes[j])
                    lst[j]++;
            
        }
        return dp[n];
    }
};