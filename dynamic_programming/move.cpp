#include<bits/stdc++.h>
using namespace std;
long long res[15][15][15][15];
int mmap[15][15];

//洛谷刷题:https://www.luogu.com.cn/problem/P1004
//方格取数

int main(){
    int n,x,y,val;
    cin>>n;
    while(1){
        cin>>x>>y>>val;
        if(x==0 && y==0 && val==0) break;
        mmap[x][y]=val;
    }
    //res[i][j][a][b]表示两条路径走到点(i,j),(a,b)所能获得的最大值
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int a=1;a<=n;a++){
                for(int b=1;b<=n;b++){
                    /*
                    那么因为两条路线有四个方向的组合,所以可以写出状态转移方程:
                    res[i][j][a][b]=max(max(res[i-1][j][a-1][b],res[i][j-1][a-1][b]),max(res[i-1][j][a][b-1],res[i][j-1][a][b-1]))+mmap[i][j],
                    最后的mmap[a][b]要考虑是否与mmap[i][j]是同一个点
                    */
                    res[i][j][a][b]=max(max(res[i-1][j][a-1][b],res[i][j-1][a-1][b]),max(res[i-1][j][a][b-1],res[i][j-1][a][b-1]))+mmap[i][j];
                    if(i!=a && j!=b)    res[i][j][a][b]+=mmap[a][b];
                }
            }
        }
    }
    cout<<res[n][n][n][n];
    system("pause");
    return 0;
}