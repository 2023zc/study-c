#include<bits/stdc++.h>
using namespace std;
int nodes[50],n,ans[50],dp[50][50],root[50][50];  //root用于记录l-->r的根节点
int dfs(int l,int mid,int r);
int getsocres(int l,int r);
int dfs(int l,int mid,int r){
    int socres_l,socres_r;
    socres_l=getsocres(l,mid-1);  //左子树的分数
    socres_r=getsocres(mid+1,r);  //右子树的分数
    return socres_l*socres_r+nodes[mid];  //总分数
}

int getsocres(int l,int r){  
    int maxx=0;
    if(l>r) return 1;  //空结点,返回1
    if(l==r) {  
        root[l][r]=l;  //记录当前结点
        return nodes[l];  //返回值
    }
    if(dp[l][r]) return dp[l][r];  //记忆化搜索
    int socres=0;
    for(int i=l;i<=r;i++){ 
        if(dfs(l,i,r)>maxx){            
            root[l][r]=i;   //记录l-->r的根节点
            maxx=dfs(l,i,r);  //记录最大值
        }
    }
    dp[l][r]=maxx;  //记忆化
    return maxx;
}

//前序遍历
void printans(int l,int r){
    if(l>r) return;  //空结点
    cout<<root[l][r]<<" ";  //当前结点
    printans(l,root[l][r]-1);  //左子树
    printans(root[l][r]+1,r);  //右子树
}

//洛谷刷题:https://www.luogu.com.cn/problem/P1040
//加分二叉树

int main(){
    int maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nodes[i];
    }
    for(int i=1;i<=n;i++){
        if(dfs(1,i,n)>maxx) {  //每个结点都当一次根节点
            root[1][n]=i;
            maxx=dfs(1,i,n);
        }
    }
    cout<<maxx<<"\n";
    printans(1,n);  //输出前序遍历
    system("pause");
    return 0;
}