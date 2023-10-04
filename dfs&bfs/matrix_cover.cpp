#include<bits/stdc++.h>
using namespace std;
#define maxx 250005
int n,k,x[55],y[55],ans=maxx;
bool book[550][550]; //标记数组,标记某个点是否被覆盖了
struct matrix{
    int lx,ly,rx,ry;  //左下点左边和右上点坐标
    void add(int x,int y){  //将点添加到矩形中
        //如果当前矩形没有点,就直接让加入的点为矩形的点
        if(!lx && !ly && !rx && !ry){
            lx=rx=x;
            ly=ry=y;
        }
        else{
            //否则就要修改范围
            if(x<lx) lx=x;
            else if(x>rx) rx=x;
            if(y<ly) ly=y;
            else if(y>ry) ry=y;            
        }
    }
    //获取面积
    int getarea(){
        return (rx-lx)*(ry-ly);
    }
    //判断点是否在矩形内部
    bool inmatrix(int x,int y){
        return x>=lx && x<=rx && y>=ly && y<=ry;
    }
}km[5];

bool check(){
    bool ans=0;
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            //判断各个矩形是否相交或重叠
            ans=ans || km[i].inmatrix(km[j].lx,km[j].ly) || km[i].inmatrix(km[j].rx,km[j].ry) || km[i].inmatrix(km[j].lx,km[j].ry) || km[i].inmatrix(km[j].rx,km[j].ly);
        }
    }
    return ans;
}

void dfs(int j,int area){   //i表示当前遍历的点,area表示当前搜索的面积
    //如果已经比最小值大就不用搜了,因为后续只会越来越大  
    if(area>ans) return;
    //到达终点
    if(j==n){
        //判断各s个矩形是否重叠
        if(!check()){
            ans=area;
        }
        return;
    }
    matrix tmp;
    for(int i=0;i<k;i++){
        if(!book[x[j]][y[j]]){
            //保留状态
            tmp=km[i];
            //添加点
            km[i].add(x[j],y[j]);
            //枚举下一个点,并求出新面积,需要减去上一个矩形的面积并加上新矩形的面积
            dfs(j+1,area-tmp.getarea()+km[i].getarea());            
            //回溯
            km[i]=tmp;
            book[x[j]][y[j]]=0;            
        }
    }
}

//洛谷刷题:https://www.luogu.com.cn/problem/P1034
//矩形覆盖

int main(){
    cin>>n>>k;   
    for(int i=0;i<n;i++){
        cin>>y[i]>>x[i];
    }
    //从0，0开始搜索
    dfs(0,0);
    cout<<ans<<"\n";
    system("pause");
    return 0;
}