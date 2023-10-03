#include<bits/stdc++.h>
using namespace std;

//洛谷刷题:https://www.luogu.com.cn/problem/P1033
//自由落体

int main(){
    double H,S1,V,L,K;
    int n;
    cin>>H>>S1>>V>>L>>K>>n;
    double t_min=sqrt((H-K)/5.0);
    double t_max=sqrt(H/5.0);
    double dis_min=(S1-t_min*V+L);
    double dis_max=(S1-t_max*V);
    //当小车超出原点时设置为0
    if(dis_max<0) dis_max=0;
    //精度判定
    else if(dis_max>int(dis_max) && dis_max-int(dis_max)<=0.0001) dis_max=int(dis_max);
    //否则就向上取整
    else dis_max=ceil(dis_max);

    //精度判定
    if(dis_min<ceil(dis_min) && ceil(dis_min)-dis_min<=0.0001){
        dis_min=ceil(dis_min);
    }
    else dis_min=int(dis_min);
    //要在坐标n-1,和dis_min之中取最小值
    int ans=min(n-1,int(dis_min))-dis_max+1;
    //如果小于1,代表最前面的点都没到,直接为0
    if(ans<0) ans=0;
    cout<<ans;
    system("pause");
    return 0;
}