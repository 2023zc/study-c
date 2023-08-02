#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
//丑数的递推性质： 丑数只包含因子2,3,5，所以丑数=某个较小丑数*丑数因子
//那么设已知第n+1个丑数:f[n+1]=min(f[a]*2,f[b]*3,f[c]*5),1<=a,b,c<=n-1
//又因为f[n]为最接近f[n+1]的丑数，所以需要满足:   f[a]*2>f[n]>=f[a-1]*2, f[a]为首个*2大于f[n]的数,其他同理
//所以我们需要可设置指针 a,b,c 指向首个丑数（即 1 ），循环根据递推公式得到下个丑数，并每轮将对应指针执行 +1 即可。
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        int nums[n];
        nums[0]=1;
        int a=0,b=0,c=0,num1,num2,num3;  //三个指针
        for(int i=1;i<n;i++){
            num1=nums[a]*2,num2=nums[b]*3,num3=nums[c]*5;
            nums[i]=min(min(num1,num2),num3);
            if(nums[i]==num1) a++;
            if(nums[i]==num2) b++;
            if(nums[i]==num3) c++;
        }
        return nums[n-1];
    }
};
int main(){
    Solution s;
    cout<<s.nthUglyNumber(10)<<"\n";
        system("pause");
        return 0;
}