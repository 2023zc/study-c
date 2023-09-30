#include<bits/stdc++.h>
using namespace std;
long long dp[85][85];

//洛谷刷题:https://www.luogu.com.cn/record/126722213
// 矩阵取数游戏

int main(){
    int n,m,matrix[85][85];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }
/*
    定义dp[i][n]表示第n步后,此时左指针指向i,所能拿到的最大值    
    状态转移方程为:dp[i][n]=max{dp[i-1][n-1]+matrix[i-1]*(2^n),dp[i][a-1]+matrix[b][m-(a-(i-1))]*(2^n)}
    其中:m-(a-(i-1))表示右边指针此时走的步数
    结束条件就是当左右指针相撞时结束
*/
    //初始化
    int maxx=0;
long long sum=0;
    dp[1][0]=0;
    for(int b=1;b<=n;b++){
        for(int i=1;i<=m;i++){
            for(int a=i-1;a<=m;a++){
                if(a){
                    //状态转移
                    dp[i][a]=max(dp[i-1][a-1]+matrix[b][i-1]*pow(2,a),dp[i][a-1]+matrix[b][m-(a-(i-1))+1]*pow(2,a));
                }
                //表示已经取完了,更新最大值
                if(a==m){
                    if(dp[i][a]>maxx) maxx=dp[i][a];
                }
            }
        }   
        //初始化,并累加最大和
        memset(dp,0,sizeof(dp));
        sum+=maxx;
        maxx=0;
    }
    cout<<sum;
    system("pause");
    return 0;

}