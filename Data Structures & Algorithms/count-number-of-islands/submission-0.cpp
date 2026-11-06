class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int check(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void dfs(int x,int y,vector<vector<char>>&grid,vector<vector<int>>&vis){
        int m = grid.size();
        int n = grid[0].size();
        vis[x][y] = 1;
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(check(nx,ny,m,n) && grid[nx][ny] == '1'){
                if(!vis[nx][ny]) dfs(nx,ny,grid,vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,vis);
                    islands++;
                }
            }
        }
        return islands;
    }
};
