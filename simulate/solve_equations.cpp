#include<bits/stdc++.h>
using namespace std;
int main(){
    //洛谷刷题:https://www.luogu.com.cn/problem/P1022
    //计算器的改良

    /*
        学习到的函数:
        stoi函数:将字符串-->int整数
        stod函数:将字符串-->double浮点数
        stol函数:将字符串-->long型整数
    */
    cout<<fixed<<setprecision(3);
    string equation;
    cin>>equation;
    //flag1表示数字前面的符号的正负,flag2表示当前数字是否在等号前面还是后面
    int flag1=1,flag2=1;
    double sum_num=0,sum_word=0;
    char word;
    for(int i=0;i<equation.size();i++){
        if(equation[i]=='-') flag1=-1;
        else if(equation[i]=='+') flag1=1;
        //当为等号时就代表到了另一边,调整flag1和flag2
        else if(equation[i]=='=') flag2=-1,flag1=1;
        else if(equation[i]>='0' && equation[i] <='9'){
            //找到数字
            string num="";
            while(i<equation.size() && equation[i]>='0' && equation[i] <='9') {
                num=num+equation[i];
                i++;   
            }
            //如果最后是字母,就代表这是字母前面的系数
            if(equation[i]>='a' && equation[i] <='z') {
                //记录字母
                word=equation[i];
                sum_word+=(stol(num)*flag1*flag2);
            }
            //否则就是数字
            else {
                sum_num+=(stol(num)*flag1*flag2);
                //如果是数字就需要让i--，后退一位
                i--;
            }
        }
        //代表是单个字母
        else {
            //记得要加1
            sum_word+=(flag1*flag2);
            word=equation[i];
        }
    }
    //最后要加上"-",是因为上面所有操作相当于化为： ax+b=0 的形式，所以最后要加上"-"
    double ans=-sum_num/sum_word;
    //特殊-0.000的情况
    if(ans==0) ans=0.000;
    cout<<word<<"="<<ans<<endl;
    system("pause");
    return 0;
}