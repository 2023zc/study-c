#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
void dfs(int deepth,int start,int maxx){  //start表示前一组的数的大小,maxx表示当前最大能取到的数
    if(deepth==k) {
        ans++;
        return;
    }
    for(int i=start;i<=maxx;i++){
        if(deepth==k-1){
            //保证最后一个数与前面各数之和为n
            if(maxx>=start){
                dfs(deepth+1,maxx,n);
            }
            //当最后一个数小于前面的数时,那么就不符合单调的性质,直接返回(剪枝)
            return;
        }
        dfs(deepth+1,i,maxx-i);                
    }
}

//洛谷刷题:https://www.luogu.com.cn/problem/P1025
//数的划分

int main(){
    cin>>n>>k;
    dfs(0,1,n);
    cout<<ans<<"\n";
    system("pause");
    return 0;
}