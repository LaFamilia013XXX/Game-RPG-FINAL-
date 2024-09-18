#include "rpg.h"
#include <iostream>
using namespace std;
#ifndef RPG_H
#define RPG_H


// Funções inimigos, declaração de valores e estruturas.

Inimigo_generico::Inimigo_generico(){
    iniciandoInimigo();
}

void Inimigo_generico::iniciandoInimigo() {
    // Inimigos Simples do Mapa;
    inimigos[TIPO1] = {10, 100};
    inimigos[TIPO2] = {13, 130};
    inimigos[TIPO3] = {16, 160};
    inimigos[TIPO4] = {19, 190};
    inimigos[TIPO5] = {22, 220};
    inimigos[TIPO6] = {25, 250};
    inimigos[TIPO7] = {28, 280};
    inimigos[TIPO8] = {31, 310};
    inimigos[TIPO9] = {34, 340};
    inimigos[TIPO10] = {37, 370};
}

int Inimigo_generico::dano(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].dano;
}

int Inimigo_generico::barraVida(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].barraVida;
}


// Lista Estatica:

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


// Stack Dinamica

Mochila::Mochila(){
    top = NULL;
}

Mochila::~Mochila(){
    int x;
    while(!Empty()){
        Pop(x);
    }
}

bool Mochila::Empty(){
    return (top == NULL);
}

bool Mochila::Full(){
    return false;
}

void Mochila::Push(int x){
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

void Mochila::Pop(int &x) { 
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

void Mochila::Clear(){ 

    int x;
    while(! Empty()){
         Pop(x);
    }
}

void Mochila::Top(int &x){ 
    if(Empty()){ 
        cout << "Pilha vazia";
        abort();
    }
    Pop(x);
    Push(x);
}

int Mochila::Size(){
    StackPointer p;
    int s=0;

    p = top;
    while(p != NULL){
        s++;
        p = p->NextNode;
    }

    return s;

}


// Stack Estatica

Cinto::Cinto() {
    top = 0;
}

Cinto::~Cinto() {
    cout << "Pilha destruinda" << endl;
}

bool Cinto::Empty() {
    return (top == 0);
}

bool Cinto::Full(){
    return ( top == MaxStack);
}

void Cinto::Push(int x) {
    if(Full()) {
        cout << "Pilha está cheia" << endl;
        abort();
    }

    top = top + 1;

    Entry[top] = x;
}

void Cinto::Pop(int &x) {
    if(Empty()){
        cout << "Pilha vazia" << endl;
        abort();
    }

    top = top - 1;

    x = Entry[top];
}

void Cinto::Clear() {
    top = 0;
}

void Cinto::Top(int &x) {
    if(Empty()) {
        cout << "Pilha vazia" << endl;
        abort();
    }

    x = Entry[top - 1];
}

int Cinto::Size(){
    return top;
}

void Cinto::exibirCinto(){
    for(int i=0; i<top; i++){
        cout << Entry[i] << endl;
    }
}


// Lista Ordenada

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








#endif