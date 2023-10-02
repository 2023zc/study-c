#include<bits/stdc++.h>
using namespace std;
#define INF 100000
int price[INF],number[INF],exceptions,downNum,e_index;
struct price_num{
    int price;
    int num;
}p_n[1000];

//洛谷刷题:https://www.luogu.com.cn/problem/P1023
//税收与补贴问题

int main(){
    memset(number,-1,sizeof(number));
    cin>>exceptions;
    int x,y,k=0,num=0,d;
    while(cin>>x>>y){
        if(x==-1 && y==-1) break;
        if(x==exceptions) e_index=num;
        //p_n用于存储每条线段的转折点
        p_n[k].price=x,p_n[k].num=y;
        if(!k) price[num]=x,number[price[num++]]=y;
        else{
            //如果发现是一条线段,并且中间的值没有输入，就要手动添加
            if(p_n[k].price>p_n[k-1].price+1){
                //算出每上升1元,销量下降的数量
                d=(p_n[k].num-p_n[k-1].num)/(p_n[k].price-p_n[k-1].price);//d<0
                //手动输入
                while(price[num-1]<p_n[k].price){
                    price[num]=price[num-1]+1;
                    //记录预期点的下标
                    if(price[num]==exceptions) e_index=num;
                    number[price[num]]=number[price[num-1]]+d;
                    num++;                    
                }
            }    
            //否则直接添加即可
            else {
                price[num]=x;
                number[price[num]]=y;
                num++;
            }
        }
        k++;
    }    

    cin>>downNum;

    //手动输入最后一条线段上的所有数字
    while(1){
        price[num]=price[num-1]+1;
        if(price[num]==exceptions){
            e_index=num;
        }
        number[price[num]]=number[price[num-1]]-downNum;
        if(number[price[num]]<=0) break;
        num++;
    }
    num--;
    int maxx=0,t=-1;
    long long money,e_money;
    //计算这其中没有补贴和税收时的利润最大值点
    for(int i=0;i<=num;i++){
        money=(price[i]-price[0])*number[price[i]];
        if(money>maxx){
            maxx=money;
            t=i;
        }
    }
    //当最大值点就是预期值时就不需要税收和补贴了
    if(t==e_index){
        cout<<"0"<<"\n";
        system("pause");
        return 0;
    }
    int sum=0,bu=0,tie=0,tmp_t;
        if(t>e_index){
            //当最大值点的价格大于预期值时,显然我们需要进行一定的补贴
            while(1){
                tmp_t=t;
                //计算预计值的收益和最大值点的收益(需要加上补贴或税收)
                money=(price[t]-price[0]+sum)*number[price[t]];
                e_money=(exceptions-price[0]+sum)*number[exceptions];
                //计算现需要补贴的值
                int bu=ceil(((money-e_money)*1.0)/((number[exceptions]-number[price[t]])*1.0));
                //记录总补贴数额
                sum+=bu;
                maxx=0;
                //找最大值点,每次只需要在预期点和最大值之间找即可
                for(int i=e_index;i<=tmp_t;i++){
                    money=(price[i]-price[0]+sum)*number[price[i]];
                    if(money>maxx){
                        maxx=money;
                        t=i;
                    }
                    //当最大值点有两个时,就取其中是预期点的那个
                    else if(money==maxx){
                        t=(i==e_index ? e_index : t);
                    }
                }              
                //当最大值点就是预期值时就结束
                if(t==e_index) break;  
            }
        }
        //下面同理,需要一定的税收
        else{
            while(1){
                tmp_t=t;
                money=(price[t]-price[0]+sum)*number[price[t]];
                e_money=(exceptions-price[0]+sum)*number[exceptions];
                int tie=ceil(((money-e_money)*1.0)/((number[price[t]]-number[exceptions])*1.0));
                sum-=tie;
                maxx=0;
                for(int i=tmp_t;i<=e_index;i++){
                    money=(price[i]-price[0]+sum)*number[price[i]];
                    if(money>maxx){
                        maxx=money;
                        t=i;
                    }
                    else if(money==maxx){
                        t=(i==e_index ? e_index : t);
                    }
                }       
                if(t==e_index) break;         
            }
        }
        cout<<sum<<"\n";
    system("pause");
    return 0;
}