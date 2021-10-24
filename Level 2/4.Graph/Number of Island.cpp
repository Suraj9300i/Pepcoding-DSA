#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& matrix,int n,int m,int r,int c){
    if(r<0 || c<0 || r>=n || c>=m || matrix[r][c]==1) return;
    matrix[r][c] = 1;
    dfs(matrix,n,m,r+1,c);
    dfs(matrix,n,m,r-1,c);
    dfs(matrix,n,m,r,c+1);
    dfs(matrix,n,m,r,c-1);
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
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                ans++;
                dfs(matrix,n,m,i,j);
            }
        }
    }
    cout<<ans;
    
    return 0;
}