#include<bits/stdc++.h>
using namespace std;
bool book[20];
int ans[200],N,M,maxx=1;
vector<int>arr;
int dp(){
    //f[i]表示凑出面值为i的面值的邮票所需要最小种数邮票面值的数量
    //有状态转移方程: f[i]=min(f[i],f[i-num[j]]+1),num[j]表示已经确认邮票面值的邮票的面值
    int f[5000];
    //初始化
    for(int i=1;i<=arr[arr.size()-1]*N;i++) f[i]=5000;
    f[0]=0;
    //状态转移
    for(int i=1;i<=arr[arr.size()-1]*N;i++){
        //保证arr[j]<i,也就是已经确定的邮票面值应当小于等于要凑到的数值
        for(int j=0;arr[j]<=i&&j<arr.size();j++){
            f[i]=min(f[i],f[i-arr[j]]+1);
        }
    }
    for(int i=1;i<=arr[arr.size()-1]*N;i++){
        //只要i不可以实现,那么i-1必定可以实现
        if(f[i]>N){
            return i-1;
        }
    }
    //都可以实现,就返回最大的数,这样可以有更多组合
    return arr[arr.size()-1]*N;
}
void dfs(int m,int deepth){  //m表示最大的边界,由dp可以获得
    //当达到M个数时,就开始比较最大值
    if(deepth==M){
        if(m>maxx){
            maxx=m;
            //更新答案
            for(int i=0;i<deepth;i++){
                ans[i]=arr[i];
            }
        }
        return;
    } 
    for(int i=arr[deepth-1]+1;i<=m+1;i++){
        arr.push_back(i);
        int mx=dp();
        dfs(mx,deepth+1);
        //回溯法
        arr.pop_back();
    }
}

//洛谷刷题:https://www.luogu.com.cn/problem/P1021
//邮票面值设计

int main(){
    cin>>N>>M;
    arr.push_back(1);
    //初始必定有个1
    dfs(N+1,1);   
    for(int i=0;i<M;i++){
        cout<<ans[i]<<' ';
    }
    cout<<"\n"<<"MAX="<<maxx<<"\n";
    system("pause");
    return 0;
}