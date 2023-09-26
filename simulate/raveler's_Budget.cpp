#include<bits/stdc++.h>
using namespace std;   
double D1,C,D2,P,N,sum;
double gas_stations[7][2];    

void head_to_next_station(double now_L,double now_distance,double price);
void to_next_Station(double now_L,double now_distance,int toStation,double price,int flag);


void head_to_next_station(double now_L,double now_distance,double price){
    //最远能到达的距离
    double max_distance=D2*C+now_distance;
    double minn=505;
    double min_to_distance=505;
    int t=-1,tt=-1;
    for(int i=0;i<N;i++){
        if(gas_stations[i][0] > now_distance && gas_stations[i][0]<=max_distance){
            //找到能到达加油站中油费最小的那个
            if(gas_stations[i][1]<minn){
                minn=gas_stations[i][1];
                tt=i;
            }
            //找到能到达加油站中比当前油费价格小,且距离最近的那个
            if(gas_stations[i][1]<price && gas_stations[i][0]<min_to_distance){
                min_to_distance=gas_stations[i][0];
                t=i;
            }
        }
    }
    double left_L,need_L;
    if(t!=-1){
        to_next_Station(now_L,now_distance,t,price,0);
    }
    else{
        //代表当前站点可以直接到达终点
        if(max_distance>=D1){
            //当前油量充足,直接结束即可
            if(now_L*D2>=(D1-now_distance)) return;
            else{
                need_L=(D1-now_distance)/D2-now_L;
                sum+=(need_L*price);
                return;
            }
        }
         //代表可以到达下一个站点
        if(tt!=-1){
            to_next_Station(now_L,now_distance,tt,price,1);
        }
        //代表即使加满油也到达不了终点和任意一个站点
        else{
            sum=0;
            cout<<"No Solution"<<"\n";
            return;
        }
    }
}
//flag表示是到达价格比上个站点的价格低的站点,还是到达一个价格比上个站点高的站点(这样就要在上个站点加满油了)
void to_next_Station(double now_L,double now_distance,int toStation,double price,int flag){
    double need_L,left_L;
    //代表当前的油量可以一步到达下一个站点
    if(!flag){
        if(now_L*D2>=(gas_stations[toStation][0]-now_distance)){
            left_L=now_L-(gas_stations[toStation][0]-now_distance)/D2;
            head_to_next_station(left_L,gas_stations[toStation][0],gas_stations[toStation][1]);
        }
        else{
            //计算需要补的油
            need_L=(gas_stations[toStation][0]-now_distance)/D2-now_L;
            sum+=(need_L*price);
            head_to_next_station(0,gas_stations[toStation][0],gas_stations[toStation][1]);
        }        
    }
    else{
        //加满油
        sum+=((C-now_L)*price);
        left_L=C-(gas_stations[toStation][0]-now_distance)/D2;
        head_to_next_station(left_L,gas_stations[toStation][0],gas_stations[toStation][1]);
    }
}
int main(){
    
//洛谷刷题:https://www.luogu.com.cn/problem/P1016
//旅行家的预算

    /*
    D1:两个城市之间距离
    C:汽车油箱的容量,以升为单位
    D2:每升油能行驶的公里数
    P:出发点每升油的价格
    N：加油站的数量(可以为0)
    */
   cout<<fixed<<setprecision(2);
    cin>>D1>>C>>D2>>P>>N;
    for(int i=0;i<N;i++){
        //Di:从起点起离加油站的距离,Pi:每升油的价格
        cin>>gas_stations[i][0]>>gas_stations[i][1];
    }
    /*
    贪心步骤:
    1.计算从当前位置最远能到达的公里数
    2.在能达到公里数只能,找到加油的价格比当前站点价格最少的那个加油站，如果没有,那就加满油,找一个加油费用最少的加油站
    3.从当前位置到达该加油站
    4.重复1，2，3步,直到到达终点
    注:如果在当前这个站点发现,即使加满油也到达不了下一个站点,那么就无解
    */
    head_to_next_station(0,0,P);
    if(sum) cout<<sum<<"\n";
    system("pause");
    return 0;
}