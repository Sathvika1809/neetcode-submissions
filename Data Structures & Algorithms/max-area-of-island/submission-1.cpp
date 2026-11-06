class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int check(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    void dfs(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&vis,int& cnt){
        int m = grid.size();
        int n = grid[0].size();
        vis[x][y] = 1;
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(check(nx,ny,m,n) && grid[nx][ny] == 1){
                if(!vis[nx][ny]){
                    cnt++;
                    dfs(nx,ny,grid,vis,cnt);
                }
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int cnt = 1;
                    dfs(i,j,grid,vis,cnt);
                    area = max(area,cnt);
                }
            }
        }
        return area;
    }
};
