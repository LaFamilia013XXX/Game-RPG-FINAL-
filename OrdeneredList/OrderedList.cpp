#include "OrderedList.h"
#include <iostream>

using namespace std;

OrderedList::OrderedList(){
    sentinel = new ListNode;
    if(sentinel == NULL) {
        cout << "Memoria Insuficiente!"<<endl;
        abort();
    }

    head = sentinel;
    count = 0;

}

OrderedList::~OrderedList(){
    ListPointer q;
    while(head != sentinel){ // Desaloca todos os conteudo até o último elemento;
        q = head;
        head = head->NextNode;
        delete q;
    }

    delete sentinel; // Deleta o sentinel;
}

bool OrderedList::Empty(){
    return head == sentinel;
}

int OrderedList::Size(){
    return count;
}

void OrderedList::Insert(int x){
    ListPointer p, q;
    sentinel->Entry = x;
    p = head;

    while(p->Entry < x){
        p = p->NextNode;
    }

    q = new ListNode;
    if( q == NULL ){
        cout << "Memoria insuficiente"<<endl;
        abort();
    }

    if(p == sentinel){
        p->NextNode = q;
        sentinel = q;
    }else{
        *q = *p;
        p->NextNode = q;
        p->Entry = x;
    }

    count++;
}


#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#endif