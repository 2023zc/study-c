#include<iostream>
using namespace std;
#define MOD 1000000007
class Solution {
public:
    int numWays(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int ans,tmp1=1,tmp2=1;
        for(int i=2;i<=n;i++){
            ans=(tmp1+tmp2)%1000000007;
            tmp1=tmp2;
            tmp2=ans;
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.numWays(n)<<"\n";
    system("pause");
}