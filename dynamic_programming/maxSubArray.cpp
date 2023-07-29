#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //f[n]表示以nums[n]结尾的连续子数列的最大值
        //状态转移方程也就为:f[n]=max(f[n-1]+nums[n],nums[n])]
        int f[nums.size()],maxx=nums[0];
        f[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            f[i]=max(nums[i],f[i-1]+nums[i]);
            if(f[i]>maxx) maxx=f[i];
        }
        return maxx;
    }
};
int main(){
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout<<s.maxSubArray(nums);
    system("pause");
}