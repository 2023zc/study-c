#include<bits/stdc++.h>
using namespace std;
/*
普通栈的 push() 和 pop() 函数的复杂度为 O(1) ；而获取栈最小值 min() 函数需要遍历整个栈，复杂度为 O(n);
本题难点： 将 min() 函数复杂度降为 O(1) 。可借助辅助栈实现：
数据栈 A ： 栈 A 用于存储所有元素，保证入栈 push() 函数、出栈 pop() 函数、获取栈顶 top() 函数的正常逻辑。
辅助栈 B ： 栈 B 中存储栈 A 中所有 非严格降序 元素的子序列，则栈 A 中的最小元素始终对应栈 B 的栈顶元素。此时， min() 函数只需返回栈 B 的栈顶元素即可。
因此，只需设法维护好 栈 B 的元素，使其保持是栈 A 的非严格降序元素的子序列，即可实现 min() 函数的 O(1) 复杂度。
*/
class MinStack {
private:
    stack<int>A,B;   
public:
    MinStack() {
    }
    void push(int x) {
        if(B.empty()||x<=B.top()){
            B.push(x);
        }
        A.push(x);
    }
    void pop() {
        if(A.top()==B.top()){
            B.pop();
        }
        A.pop();
    }
    
    int top() {
        return A.top();
    }
    int min() {
        return B.top();
    }
};
int main(){
    
}