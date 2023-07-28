#include<bits/stdc++.h>
using namespace std;
class MaxQueue {
private:
    queue<int>max_queue;        
    deque<int>tmp;   //用递减队列维护最大值
public:
    MaxQueue() {}
    int max_value() {
        if(tmp.empty()){
            return -1;
        }
        return tmp.front();
    }
    
    void push_back(int value) {
        max_queue.push(value);
        if(tmp.empty()){
            tmp.push_back(value);
            return;
        }
        while(!tmp.empty()&&tmp.back()<value){
            tmp.pop_back();
        }
        tmp.push_back(value);
    }
    
    int pop_front() {
        if(max_queue.empty()){
            return -1;
        }
        int head=max_queue.front();
        max_queue.pop();
        if(head==tmp.front()){
            tmp.pop_front();
        }
        return head;
    }
};
int main(){
    MaxQueue mq;
    for(int i=0;i<10;i++){
        cout<<(i%3+1)<<" ";
        mq.push_back(i%3+1);
    }
    cout<<"\n----------------\n";
    for(int i=0;i<12;i++){
        cout<<mq.max_value()<<"\n";
        mq.pop_front();
    }
    system("pause");
}
/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */