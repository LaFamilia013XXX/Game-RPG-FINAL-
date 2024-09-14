#include "Stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Stack::Stack() {
    top = 0;
}

Stack::~Stack() {
    cout << "Pilha destruinda" << endl;
}

bool Stack::Empty() {
    return (top == 0);
}

bool Stack::Full(){
    return ( top == MaxStack);
}

void Stack::Push(int x) {
    if(Full()) {
        cout << "Pilha está cheia" << endl;
        abort();
    }

    top = top + 1;

    Entry[top] = x;
}

void Stack::Pop(int &x) {
    if(Empty()){
        cout << "Pilha vazia" << endl;
        abort();
    }

    top = top - 1;

    x = Entry[top];
}

void Stack::Clear() {
    top = 0;
}

void Stack::Top(int &x) {
    if(Empty()) {
        cout << "Pilha vazia" << endl;
        abort();
    }

    x = Entry[top - 1];
}

int Stack::Size(){
    return top;
}

void Stack::exibirStack(){
    for(int i=0; i<top; i++){
        cout << Entry[i] << endl;
    }
}