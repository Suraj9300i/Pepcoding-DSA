#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& grid,int n,int m,int r,int c){
    if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==0) return 0;
    grid[r][c] = 0;
    int cnt = 1;
    cnt += dfs(grid,n,m,r+1,c);
    cnt += dfs(grid,n,m,r-1,c);
    cnt += dfs(grid,n,m,r,c+1);
    cnt += dfs(grid,n,m,r,c-1);
    return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                dfs(grid,n,m,i,j);
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                ans += dfs(grid,n,m,i,j);
            }
        }
    }
    cout<<ans;
    
    return 0;
}