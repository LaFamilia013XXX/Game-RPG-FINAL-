#include "Stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Stack::Stack(){
    top = NULL;
}

Stack::~Stack(){
    int x;
    while(!Empty()){
        Pop(x);
    }
}

bool Stack::Empty(){
    return (top == NULL);
}

bool Stack::Full(){
    return false;
}

void Stack::Push(int x){
    StackPointer p;

    p = new StackNode;

    if(p == NULL) {
        cout << "Memoria insuficiente";
        abort();
    }

    p->Entry = x;
    p->NextNode = top;
    top = p;
}

void Stack::Pop(int &x) { 
    StackPointer p;

    if (Empty())
    { cout << "Pilha Vazia";
        abort();
    }
    
    x = top->Entry;
    p = top;
    top = top->NextNode;
    delete p;
}

void Stack::Clear(){ 

    int x;
    while(! Empty()){
         Pop(x);
    }
}

void Stack::Top(int &x){ 
    if(Empty()){ 
        cout << "Pilha vazia";
        abort();
    }
    Pop(x);
    Push(x);
}

int Stack::Size(){
    StackPointer p;
    int s=0;

    p = top;
    while(p != NULL){
        s++;
        p = p->NextNode;
    }

    return s;

}