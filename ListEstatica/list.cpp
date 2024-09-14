#include "List.h"
#include <iostream>
#include <cstdlib>

using namespace std;

List::List(){
    count = 0;
}

List::~List(){
    cout << "Lista destruida";
}

bool List::Empty(){
    return (count == 0);
}

bool List::Full(){
    return (count == MaxList);
}

void List::Insert(int p,int x){ 
    int i;
    if (Full()){ 
        cout << "Lista Cheia";
        abort();
    }
    if (p < 1 || p > count+1){ 
        cout << "Posicao invalida";
        abort();
    }
    for(i=count; i>=p; i--){
        Entry[i+1] = Entry[i];
    }
    Entry[p] = x;
    count++;
}

void List::Delete(int p, int &x){ 
    int i;
    if (Empty()){ 
        cout << "Lista Vazia";
        abort();
    }   
    if (p < 1 || p > count){ 
        cout << "Posicao invalida";
        abort();
    }
    x = Entry[p];
    for(i=p; i<count; i++){
        Entry[i] = Entry[i+1];
    }
    count = count - 1;
        
}

void List::Clear(){
    count = 0;
}

int List::Size(){
    return count;
}

void List::Retrieve(int p, int&x){ 
    if(p < 1 || p > count){ 
        cout << "Posicao invalida";
        abort();
    }
    x = Entry[p];

    cout << x << endl;
}

void List::Replace(int p, int x){ 
    if(p < 1 || p > count){ 
        cout << "Posicao invalida";
        abort();
    }
    Entry[p] = x;
}

void List::exibirList(){
    for(int i=0; i<count; i++){
        cout << "Posicao " << i << " " << Entry[i+1] << endl;
    }
}