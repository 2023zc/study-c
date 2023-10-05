#include<bits/stdc++.h>
using namespace std;
int n,p;
#define maxx 0xfffffff
struct node{
    int C;  //信号强度
    int U;  //阈值
}nodes[105];
//邻接矩阵建图
int nodeMatrix[105][105];
//记忆化,记忆每个点更新后的C值
int book[105];
//存储输出层的点
vector<int> poss;
//从输出层开始向上设置每一层的C值
int setC(int pos){
    //记忆化
    if(book[pos]!=maxx) return book[pos];
    for(int i=1;i<=n;i++){
        //表示找上一层的与之相连的神经元
        if(nodeMatrix[i][pos]){
            //注意:只有上一层大于零才计入
            if(setC(i)>0){
                nodes[pos].C+=(setC(i)*nodeMatrix[i][pos]);
            }
        }
    }
    //记得减去阈值
    nodes[pos].C-=nodes[pos].U;
    //记忆化
    book[pos]=nodes[pos].C;
    return nodes[pos].C;
}


//洛谷刷题:https://www.luogu.com.cn/problem/solution/P1038?orderBy=weight&page=1
//神经网络


int main(){
    int x,y,val,flag=0;
    cin>>n>>p;    
    //初始化
    for(int i=1;i<=n;i++) book[i]=maxx;
    for(int i=1;i<=n;i++){
        cin>>nodes[i].C>>nodes[i].U;
        nodes[i].C!=0 ? book[i]=nodes[i].C : 0; 
    }
    //建图
    for(int j=1;j<=p;j++){
        cin>>x>>y>>val;
        nodeMatrix[x][y]=val;
    }
    //找出输出层的点的标号
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(nodeMatrix[i][j]) {
                flag=1;
                break;
            }
        }
        if(!flag){
            poss.push_back(i);
        }
        flag=0;
    }
    //从输出层开始遍历
    for(int i=0;i<poss.size();i++){
        int socre=setC(poss[i]); 
        if(socre>0){
            flag=1;
            cout<<poss[i]<<" "<<socre<<"\n";
        }
    }
    if(!flag) cout<<"NULL"<<"\n";
    system("pause");
    return 0;
}