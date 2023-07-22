#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size()==0 || k==0) return res;
        deque<int> d;
        for (int j=0, i=1-k; j<nums.size(); i++, j++) {
            if (i>0 && d.front()==nums[i-1]) d.pop_front();    //将划走的元素再单调队列中删除
            while (!d.empty() && d.back() < nums[j]) d.pop_back();  //保证队列是单调队列
            d.push_back(nums[j]);   //将新加入的元素加到队尾
            if (i>=0) res.push_back(d.front());  //因为为单调队列，所以队头就是最大值
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int>s1={1,3,-1,-3,5,3,6,7};
    vector<int>ans=s.maxSlidingWindow(s1,3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    system("pause");
}