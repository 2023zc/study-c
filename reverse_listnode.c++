#include<bits/stdc++.h>
using namespace std;
struct ListNode {   //链表节点的定义
     int val;  //值
     ListNode *next;   //后继
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(){}
};
class List {
public:
    ListNode* head;  //头节点
    List(){
        head=NULL;    //一开始的链表没有任何元素，所以头节点初始化为NULL
    }
    ListNode* reverseList() {  //反转链表
        ListNode * pre=NULL;    //当前节点的前一个节点，因为要反转链表，所以前一个节点为NULL
        ListNode * cur=head;  //当前的节点
        ListNode * tmp;    //暂时存放当前节点的下一个节点    
        while(cur){
            tmp=cur->next;   //存放下一个节点
            cur->next=pre;   //让当前节点指向前一个结点
            pre=cur;   //更新前一个节点至当前节点
            cur=tmp;  //更新当前节点至下一个节点1
        }
        this->head=pre;   //更新头节点
        return this->head;  //返回反转后的头节点
    }
    void addNode(int val){  //添加节点
        ListNode*new_node=new ListNode(val);
        if(head==NULL){
            head=new_node;
            new_node->next=NULL;
            return;
        }
        ListNode*cur=head;
        while(cur){
            if(cur->next==NULL){
                cur->next=new_node;
                new_node->next=NULL;
                break;
            }
            cur=cur->next;
        }
    }
    void insertNode(int val,int index){   //插入至指定下标后面
        int count=0;  //计数
        ListNode *cur=head;
        ListNode * new_node=new ListNode(val);
        while(cur){
            cur=cur->next;
            count++;
            if(count==index){
                new_node->next=cur->next;  
                cur->next=new_node;   //插入到指定下标后一位
            }
        }
    }
    ListNode * searchNode(int index){   //查找指定下标的节点
        ListNode * cur=head;
        int count=0;
        while(cur){             
            if(count==index){
                return cur;
            }           
            cur=cur->next;
            count++;
        }
        return cur;
    }
    void display(){   //打印当前链表
        ListNode*cur=head;
        while(cur){            
            cout<<cur->val<<" ";
            cur=cur->next;
        }
    }
};
int main(){
    List list;
    for(int i=0;i<10;i++){
        list.addNode(i);       
    }
    list.display();
    cout<<"\n";
    list.reverseList();    
    list.display();
    cout<<"\n";
    list.insertNode(2,1);
    list.display();
    system("pause");
}