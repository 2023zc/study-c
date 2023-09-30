#include<bits/stdc++.h>
using namespace std;
int sum(int n){
    return (n+1)*n/2;
}
int search(int target){
    int l=0,r=10000,mid;;
    while(l!=r-1){
        mid=(l+r)/2;
        if(sum(mid)<target) l=mid;
        else if(sum(mid-1)>=target) r=mid;
        else if(sum(mid)>=target && sum(mid-1)<target) break;
    }
    return mid;
}

//洛谷刷题:https://www.luogu.com.cn/problem/P1014
//Cantor 表

int main(){
    int n,ans_up,ans_down;
    cin>>n;
    int num=search(n);
//偶数,下面较大
    if(!(num%2)){
        ans_up=n-sum(num-1),ans_down=num-(n-sum(num-1))+1;
    }
    else{
        ans_up=num-(n-sum(num-1))+1,ans_down=n-sum(num-1);
    }
    cout<<ans_up<<"/"<<ans_down<<"\n";
    system("pause");
    return 0;
}