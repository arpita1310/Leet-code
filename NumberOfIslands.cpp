class Solution {
public:
    bool abc(vector<vector<char>>&G, int i, int j)
    {
        if(i<0||j<0||i>=G.size()||j>=G[0].size())
            return true;        
        if (G[i][j] == '0')
            return true;        
        G[i][j]='0';
        bool p=abc(G,i+1,j), q=abc(G,i,j+1), r=abc(G,i-1,j), s=abc(G,i,j-1);
        return p && q && r && s;
    }

    int numIslands(vector<vector<char>>& grid) {
        int k=0;
        for (int i=0;i<grid.size();i++)
            for (int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1')
                {
                    if(abc(grid,i,j))
                       k++;
                }       
        return k;
    }
    
};