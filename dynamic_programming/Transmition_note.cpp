#include<bits/stdc++.h>
using namespace std;
long long matrix[60][60],arr[120][60][60];
int main(){

//洛谷刷题:https://www.luogu.com.cn/problem/P1006
//传纸条

    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    //初始化
    memset(arr,-1,sizeof(arr));
    arr[2][1][1]=0;
    //两条路径相当于从左上角走两条不重叠的路径到达右下角,则在运动过程中两个点必定位于同一条斜线上  
    /*
    状态定义:arr[k][i][j],其中k表示这条斜线的横纵坐标之和,i表示纵坐标相对在左边的点的纵坐标,j表示纵坐标相对在右边的点的纵坐标
    那么状态转移方程为: arr[k][i][j]=max{arr[k-1][i][j],arr[k-1][i-1][j],arr[k-1][i][j-1],arr[k-1][i-1][j-1]}(表示四个方向移动)
    */
    for(int k=3;k<m+n;k++){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int s=arr[k][i][j];
                //表示四个方向,两个点的方向组合,下面数据以(纵坐标相对在左边的点移动方向,纵坐标相对在右边的点的移动方向)显示:
                /*
                (下,下),(下,右),(右,右),(右,下)
                */
                if(arr[k-1][i][j]>s) s=arr[k-1][i][j];  //(下,下)
                if(arr[k-1][i][j-1]>s) s=arr[k-1][i][j-1];  //(下,右)
                if(arr[k-1][i-1][j-1]>s) s=arr[k-1][i-1][j-1];  //(右,右)
                if(arr[k-1][i-1][j]>s) s=arr[k-1][i-1][j]; //(右,下)
                if(s==-1) continue;   //代表到达不了该点
                //最后的值就是前面arr的最大值加上接下来的两点的值的总和
                arr[k][i][j]=s+matrix[k-i][i]+matrix[k-j][j];
            }
        }
    }
    //到达不了最后一个点,但是能到达(m,n)点的左边点和上面的点
    cout<<arr[m+n-1][n-1][n];
    return 0;
}