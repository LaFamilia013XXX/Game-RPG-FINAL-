#include "List.h"
#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H



List::List()
{
    count = 0;
    head = NULL;
}

List::~List(){
    ListPointer q;

while(head!=NULL)
{
q = head;
head = head ->NextNode;
delete q;
}

}
bool List::Empty(){
    return count == 0;
}

void List::Insert(int x, int p){
if(p <1 || p > +1){
    cout << "Posicao invalida"<<endl;
    abort();

}
ListNode *newNode;
newNode = new ListNode;
if (newNode == NULL){
    cout << "sem espaco para o novo elemento"<<endl;
    abort();
}

newNode -> Entry = x;
if (p == 1){
    newNode-> NextNode = head;
    head = newNode;

}else{
    ListNode  *q;
    SetPosition(p - 1, q);
    newNode -> NextNode = q -> NextNode;
    q -> NextNode = newNode;
}
count ++;

}
void List::Delete(int &x, int p){

    if (p < 1 || p > count ){

        cout<<"posicao invalida"<< endl;
        abort();
    }
    ListNode *Node;
    if (p == 1){
        Node = head;
        head = head-> NextNode;
        
    }else{
        ListNode *q;
        SetPosition(p-1, q);
        Node = q -> NextNode;
        
        q -> NextNode = Node -> NextNode;  

    }
    x = Node -> Entry;
    delete Node;
    count -- ;
}

void List::SetPosition(int p, ListPointer &current){
    current = head;
    for(int i = 2; i <= p; i++){
        current = current -> NextNode;

    }
}
    void List::Clear(){
        ListNode *q;
        while(head != NULL ){
            q = head;
            head = head -> NextNode;
            delete q;
        }
count = 0;
    }
    void List::Replace(int x, int p){
        if (p < 1 || p > count){
            cout<<"posicao invalida"<< endl;
            abort();
        }
        ListNode *Node;
        SetPosition(p, Node);
        Node-> Entry = x;

    }
void List::Retrieve(int &x, int p){
    if (p < 1 || p > count){
        cout<< "posicao invalida"<< endl;
        abort();

    }
    ListNode *Node;
    SetPosition(p, Node);
    x = Node -> Entry;
}

#endif