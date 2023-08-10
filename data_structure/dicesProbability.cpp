#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> dicesProbability(int n) {
        double dp[12][67];  //dp[n][k]表示n个骰子掷出k点的概率
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=6;i++){
            dp[1][i]=1.0/6.0;    //初始条件
        }
        //n个骰子能投出的范围为:n-6n  , 从2个骰子开始
        for(int j=2;j<=n;j++){
            for(int i=j;i<=6*j;i++){
                for(int a=1;a<=i-1;a++){
                    dp[j][i]+=(dp[j-1][a]*dp[1][i-a]);  //转移方程为: dp[n][k]=sum(dp[n-1][a]*dp[1][k-a])  1<=a<=i-1
                }
            }            
        }
        vector<double> ans;
        for(int i=n;i<=6*n;i++){
            ans.push_back(dp[n][i]);  //赋值
        }
        return ans;
    }
};
int main(){
    cout<<fixed<<setprecision(5);
    vector<double> ans;
    Solution s;
    ans=s.dicesProbability(11);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    system("pause");
    return 0;
}