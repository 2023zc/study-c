#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //可设dp[n][m]表示移动到grid[n][m]可得到的最大价值
        //那么很显然，dp[n][m]=max(dp[n-1][m]+grid[n][m],dp[n][m-1]+grid[n][m]])
        //那么显然,dp[n][m]只与dp[n]与dp[n-1]这两个向量有关，那么我们就可以压缩为一维
        int m=grid.size(),n=grid[0].size();
        //初始化:
        int dp[2][n];
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }

        //状态转移
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j-1>=0)      dp[i%2][j]=max(dp[(i-1)%2][j]+grid[i][j],dp[i%2][j-1]+grid[i][j]);                      
                else    dp[i%2][j]=dp[(i-1)%2][j]+grid[i][j];
            }
        }

        return dp[(m-1)%2][n-1];
    }
};
//1,3,1
//1,5,1
//4,2,1
int main(){
    Solution s;
    vector<vector<int> > grid={{1,3,1},{1,5,1},{4,2,1}};
    cout<<s.maxValue(grid);
    system("pause");
    return 0;
}