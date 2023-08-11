#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int now=1,maxx,minn;
        if(prices.size()==0||prices.size()==1) return 0;
        while(prices[now]<=prices[now-1]){
            now++;  //找到第一个可以买的股票的后一位   
            if(now==prices.size()){
                break;
            }
        } 
        if(now == prices.size()) return 0;  //表示递减数列
        maxx=(prices[now]-prices[now-1]),minn=prices[now-1]; //初始化
        for(int i=now+1;i<prices.size();i++){
            if(prices[i]<minn) minn=prices[i]; //更新最小值
            if(prices[i]-minn>maxx) maxx=prices[i]-minn;  //更新最大值
        }
        return maxx;
    }
};
int main(){
    Solution s;
    vector<int> a ={7,6,4,3,1};
    cout<<s.maxProfit(a)<<"\n";
    system("pause");
    return 0;
}