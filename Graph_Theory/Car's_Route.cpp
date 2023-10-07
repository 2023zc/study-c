#include<bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    int city;
    //求两点之前的距离
    double operator*(const point &p2){
        return sqrt(pow(x-p2.x,2)+pow(y-p2.y,2));
    }
}pointarr[450],tmp[5];
/*
    S 表示城市的个数，
    t 表示飞机单位里程的价格，
    A，B 分别为城市A，B 的序号
*/
int n,S,t,A,B,x,y,T[150];
//邻接矩阵存图
double dis[450][450];
/*
    获取从i点到j点的权值
*/
double getweight(int i,int j){
    //是同一个城市
    if(pointarr[i].city==pointarr[j].city){
        return (pointarr[i]*pointarr[j])*T[pointarr[i].city];
    }
    //不是同一个城市
    else{
        return (pointarr[i]*pointarr[j])*t;
    }    
}

//初始化权值
void init(){
    for(int i=1;i<=4*S;i++){
        for(int j=1;j<=4*S;j++){
            dis[i][j]=getweight(i,j);
        }
    }
}
//向量法求第四个点的坐标
point findanother(){
    point ans;
    if(!((tmp[1].x-tmp[2].x)*(tmp[1].x-tmp[3].x)+(tmp[1].y-tmp[2].y)*(tmp[1].y-tmp[3].y))){
        ans.x=tmp[2].x+tmp[3].x-tmp[1].x;
        ans.y=tmp[2].y+tmp[3].y-tmp[1].y;
    }
    else if(!((tmp[2].x-tmp[1].x)*(tmp[2].x-tmp[3].x)+(tmp[2].y-tmp[1].y)*(tmp[2].y-tmp[3].y))){
        ans.x=tmp[1].x+tmp[3].x-tmp[2].x;
        ans.y=tmp[1].y+tmp[3].y-tmp[2].y;
    }
    else{
        ans.x=tmp[1].x+tmp[2].x-tmp[3].x;
        ans.y=tmp[2].y+tmp[1].y-tmp[3].y;
    }
    return ans;
}

//洛谷刷题:https://www.luogu.com.cn/problem/P1027
//Car 的旅行路线


int main(){
    cin>>n;
    for(int i1=0;i1<n;i1++){
        cin>>S>>t>>A>>B;
        for(int i=1;i<=S;i++){
            for(int j=1;j<=3;j++){
                cin>>x>>y;
                //输入坐标和手动输入该点所在城市
                pointarr[(i-1)*4+j].x=x,pointarr[(i-1)*4+j].y=y,pointarr[(i-1)*4+j].city=i;           
                tmp[j].x=x,tmp[j].y=y;
            }
            //求出第4个点的坐标
            point ans=findanother();
            pointarr[(i-1)*4+4].x=ans.x,pointarr[(i-1)*4+4].y=ans.y,pointarr[(i-1)*4+4].city=i;
            cin>>T[i];
        }    
        //记得初始化
        init();
        //Floyd算法
        for(int i=1;i<=4*S;i++){
            for(int a=1;a<=4*S;a++){
                for(int b=1;b<=4*S;b++){
                    if(dis[a][b]>dis[a][i]+dis[i][b]){
                        dis[a][b]=dis[a][i]+dis[i][b];
                    }   
                }
            }
        }

        //找从A城市到B城市的最小值
        double minn=9999999;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                if(dis[(A-1)*4+i][(B-1)*4+j]<minn){
                    minn=dis[(A-1)*4+i][(B-1)*4+j];
                }                
            }
        }
        //记得保留一位小数!
        cout<<fixed<<setprecision(1);
        cout<<minn<<"\n";
    }


    system("pause");
    return 0;
}