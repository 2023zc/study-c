#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //可设f[n]表示以s[n]为结尾的最长非重复子串的长度
        //那么显然,可推出转态转移方程为：
        //f[n]=f[n-1]+1  s[n]与之前的字符都不重复;     f[n]=(n-k)+1  s[n]与之前的第k个字符重复,  然后，我们只需取f[n]中的最大值即可
       //那么显然,我们需要一个hashmap来记录之前的每个字符分别在那个下标下,如果没有加入哈希表就加入表示已经有这个字符了
       //这里
       if(s=="") return 0;
       int f[s.size()],max=1,str[128],pre=0;  //cur表示前指针,pre表示后指针
       memset(str,-1,sizeof(str));       
       str[s[0]]=0; //初始化
        for(int i=1;i<s.size();i++){

            int index=s[i];
            //判断是否重复
            if(str[index]==-1)  str[index]=i;  //没重复就记录下标  
            else{
                for(int j=pre;j<str[index];j++)  str[s[j]]=-1;   //更新当前字符
                pre=str[index]+1;   //更新后指针
                str[index]=i;  //更新下标         
            }
            if(i-pre+1>max) max=i-pre+1;   //更新最大值  
        }
        return max;
    }
};
int main(){
    string a="abba";
    Solution s;
    cout<<s.lengthOfLongestSubstring(a)<<"\n";
    system("pause");
    return 0;
}