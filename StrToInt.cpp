#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        long long  n=0,max_inf=pow(2,31)-1,min_inf=-pow(2,31),sum=0;
        while(str[n]==' ') n++;

        //符号为'-'时处理
        if(str[n]=='-'){
            n++;
            while(n<str.size()&&(str[n]>='0'&&str[n]<='9')){                
                sum=sum*10-(str[n]-'0');
                n++;
                if(sum<min_inf)  return min_inf;
            }
        }
        //符号为'+'时处理
        else if(str[n]=='+'){
            n++;
            while(n<str.size()&&(str[n]>='0'&&str[n]<='9')){                
                sum=sum*10+(str[n]-'0');
                n++;
                if(sum>max_inf)  return max_inf;
            }
        }
        //首位为数字时处理
        else if(str[n]>='0'&& str[n]<='9'){
            sum=(sum*10)+(str[n]-'0');
            n++;
            while(n<str.size()&&(str[n]>='0'&&str[n]<='9')){                
                sum=sum*10+(str[n]-'0');
                n++;
                if(sum>max_inf)  return max_inf;
            }
        }
        //其他情况就为0
        else return 0;
        return sum;
    }
};
int main(){
    Solution S;
    cout<<S.strToInt(" b11228552307")<<"\n";
    system("pause");
}