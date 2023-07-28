#include<iostream>
using namespace std;
#define MOD 1000000007
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int ans=1,tmp1=0,tmp2=0;
        for(int i=2;i<=n;i++){
            tmp1=tmp2;
            tmp2=ans;   //因为结果只跟前面两个数有关，所以只需要两个变量
            ans=(tmp1+tmp2)%MOD;   //记得求余
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.fib(n)<<"\n";
    system("pause");
}