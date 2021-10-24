#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> dx = {0,0,1,-1};
vector<int> dy  = {1,-1,0,0};
vector<char> dir  = {'r','l','b','t'};
void dfs(vector<vector<int>>& grid,int n,int m,int r,int c,string& shape){
    grid[r][c] = 0;

    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]==0)
            continue;
        shape.push_back(dir[i]);
        dfs(grid,n,m,nr,nc,shape);
        shape.push_back('#');
    }
    
}

int numberofDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    unordered_set<string> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                string shape = "s";
                dfs(grid,n,m,i,j,shape);
                st.insert(shape);
            }
        }
    }
    return st.size();
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    
    cout<<numberofDistinctIslands(matrix);
    
    return 0;
}