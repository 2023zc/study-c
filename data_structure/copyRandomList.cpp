#include<bits/stdc++.h>
using namespace std;

//复制随机链表，链表不仅有next,还有一个指向随机节点的random
class Node {   //随机链表节点
public:
    int val;
    Node* next;
    Node* random;   //包含一个随机链表节点，会指向任意一个节点或者null
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
private:
    Node* new_head;
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>hashmap;
        Node* cur=head;
        while(cur){
            Node* new_node=new Node(cur->val);
            hashmap[cur]=new_node;
            cur=cur->next;
        }  //建立原链表和新链表的一一映射关系
        cur=head;
        while(cur){
            hashmap[cur]->next=hashmap[cur->next];
            hashmap[cur]->random=hashmap[cur->random];
            cur=cur->next;
        }        //建立新链表的next和random关系
        Node* new_head=hashmap[head];
        return new_head;
    
    }
};
int main(){

}