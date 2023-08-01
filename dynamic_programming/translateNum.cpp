#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int translateNum(int num) { 
        //dp[0][n]表示以Numstr[n]结尾的，最后一个字母对应的的数字是单独Numstr[n]一个的方法总数,
        //Numstr[1][n]表示最后一个字母应的数字是Numstr[n]与Numstr[n-1]组合的方法总数
        //那么状态转移方程为:
        //1.dp[0][n]=dp[0][n-1]+dp[1][n-1];
        //2.dp[1][n]=dp[0][n-1]   if(组合的数<=25&&组合的数!=Numstr[n])   =0  if(组合的数>25)  
        //最后总数结果为:dp[0][n]+dp[1][n];
        //可以发现dp的当前结果只与前一轮循环的两个数有关,故可以压缩成两个数
        int ans1=1,ans2=0,tmp1=1,tmp2=0;   //ans1表示dp[0][n],ans1表示dp[1][n];

        string Numstr=to_string(num);
        for(int i=1;i<Numstr.size();i++){
            ans1=tmp1+tmp2;    //第一个方程

            //第二个方程
            if(Numstr[i-1]!='0'&&(((Numstr[i]-'0')+(Numstr[i-1]-'0')*10)<=25)){
                ans2=tmp1;
            }
            else{
                ans2=0;
            }

            tmp1=ans1,tmp2=ans2;   //更新前面的结果


        }
        return ans1+ans2;
    }
};
int main(){
    Solution s;
    cout<<s.translateNum(508);
    system("pause");
    return 0;
}