#include "rpg.h"
#include <iostream>
#include<string>
using namespace std;
#ifndef RPG_H
#define RPG_H


// Classes de itens e seu atributos;

// Declarando as Structs para cada tipo de item (Coloquei tudo dentro de uma função void);

CriandoItem espada_comum;
CriandoItem espada_raro;
CriandoItem espada_lendario;
CriandoItem espada_epico;
CriandoItem machado_comum;
CriandoItem machado_raro;
CriandoItem machado_lendario;
CriandoItem machado_epico;
CriandoItem Varinha_comum;
CriandoItem Varinha_raro;
CriandoItem Varinha_lendario;
CriandoItem Varinha_epico;
CriandoItem pocaoDeCura_comum;
CriandoItem pocaoDeCura_raro;
CriandoItem pocaoDeCura_lendario;
CriandoItem pocaoDeCura_epico;
CriandoItem vazio;

// Chamando a função void:

Item::Item(){
    IniciandoItem();
}

void Item::IniciandoItem() {

    itens[POCAODECURA_COMUM] = {0, "Pocao Cura - Comum", 10, 50, 0};  // dano, peso, cura e defesa
    itens[POCAODECURA_RARO] = {0, "Pocao Cura - Raro", 20, 75, 0}; 
    itens[POCAODECURA_LENDARIO] = {0, "Pocao Cura - Lendario", 30, 100, 0};
    itens[POCAODECURA_EPICO] = {0, "Pocao Cura - Epico", 40, 150, 0};

    itens[ESPADA_COMUM] = {15, "Espada - Comum", 10, 0, 0}; 
    itens[ESPADA_RARO] = {20, "Espada - Raro", 20, 0, 0}; 
    itens[ESPADA_LENDARIO] = {25, "Espada - Lendario", 30, 0, 0};
    itens[ESPADA_EPICO] = {30, "Espada - Epico", 40, 0, 0};

    itens[MACHADO_COMUM] =    {10, "Machado - Comum", 10, 0, 0}; 
    itens[MACHADO_RARO] =     {15, "Machado - Raro", 20, 0, 0}; 
    itens[MACHADO_LENDARIO] = {20, "Machado - Lendario", 30, 0, 0};
    itens[MACHADO_EPICO] =    {25, "Machado - Epico", 40, 0, 0};

    itens[VARINHA_COMUM] =    {10, "Varinha - Comum", 10, 0, 0}; 
    itens[VARINHA_RARO] =     {15, "Varinha - Raro", 20, 0, 0}; 
    itens[VARINHA_LENDARIO] = {20, "Varinha - Lendario", 30, 0, 0};
    itens[VARINHA_EPICO] =    {25, "Varinha - Epico", 40, 0, 0};

    itens[VAZIO] = {0, "vazio", 0, 0, 0};
};

int Item::Dano(Tipo tipo) const {
    return itens[tipo].Dano;
}

int Item::Cura(Tipo tipo) const {
    return itens[tipo].Cura;
}

string Item::Nome(Tipo tipo) const {
    return itens[tipo].Nome;
}

int Item::Defesa(Tipo tipo) const {
    return itens[tipo].Defesa;
}

int Item::Peso(Tipo tipo) const {
    return itens[tipo].Peso;
}

// Função que irá atribuir os valores para cada tipo de item, o qual deve ser chamada no inicio do código, antes da chamada de todos os itens;

void criandoItens(){

    Item ItemCriador;

    espada_comum = {ItemCriador.Dano(ESPADA_COMUM), ItemCriador.Nome(ESPADA_COMUM), ItemCriador.Peso(ESPADA_COMUM), ItemCriador.Cura(ESPADA_COMUM), ItemCriador.Defesa(ESPADA_COMUM)};
    espada_raro = {ItemCriador.Dano(ESPADA_RARO), ItemCriador.Nome(ESPADA_RARO), ItemCriador.Peso(ESPADA_RARO), ItemCriador.Cura(ESPADA_RARO), ItemCriador.Defesa(ESPADA_RARO)};
    espada_lendario = {ItemCriador.Dano(ESPADA_LENDARIO), ItemCriador.Nome(ESPADA_LENDARIO), ItemCriador.Peso(ESPADA_LENDARIO), ItemCriador.Cura(ESPADA_LENDARIO), ItemCriador.Defesa(ESPADA_LENDARIO)};
    espada_epico = {ItemCriador.Dano(ESPADA_EPICO), ItemCriador.Nome(ESPADA_EPICO), ItemCriador.Peso(ESPADA_EPICO), ItemCriador.Cura(ESPADA_EPICO), ItemCriador.Defesa(ESPADA_EPICO)};
    
    machado_comum = {ItemCriador.Dano(MACHADO_COMUM), ItemCriador.Nome(MACHADO_COMUM), ItemCriador.Peso(MACHADO_COMUM), ItemCriador.Cura(MACHADO_COMUM), ItemCriador.Defesa(MACHADO_COMUM)};
    machado_raro = {ItemCriador.Dano(MACHADO_RARO), ItemCriador.Nome(MACHADO_RARO), ItemCriador.Peso(MACHADO_RARO), ItemCriador.Cura(MACHADO_RARO), ItemCriador.Defesa(MACHADO_RARO)};
    machado_lendario = {ItemCriador.Dano(MACHADO_LENDARIO), ItemCriador.Nome(MACHADO_LENDARIO), ItemCriador.Peso(MACHADO_LENDARIO), ItemCriador.Cura(MACHADO_LENDARIO), ItemCriador.Defesa(MACHADO_LENDARIO)};
    machado_epico = {ItemCriador.Dano(MACHADO_EPICO), ItemCriador.Nome(MACHADO_EPICO), ItemCriador.Peso(MACHADO_EPICO), ItemCriador.Cura(MACHADO_EPICO), ItemCriador.Defesa(MACHADO_EPICO)};
    
    Varinha_comum = {ItemCriador.Dano(VARINHA_COMUM), ItemCriador.Nome(VARINHA_COMUM), ItemCriador.Peso(VARINHA_COMUM), ItemCriador.Cura(VARINHA_COMUM), ItemCriador.Defesa(VARINHA_COMUM)};
    Varinha_raro = {ItemCriador.Dano(VARINHA_RARO), ItemCriador.Nome(VARINHA_RARO), ItemCriador.Peso(VARINHA_RARO), ItemCriador.Cura(VARINHA_RARO), ItemCriador.Defesa(VARINHA_RARO)};
    Varinha_lendario = {ItemCriador.Dano(VARINHA_LENDARIO), ItemCriador.Nome(VARINHA_LENDARIO), ItemCriador.Peso(VARINHA_LENDARIO), ItemCriador.Cura(VARINHA_LENDARIO), ItemCriador.Defesa(VARINHA_LENDARIO)};
    Varinha_epico = {ItemCriador.Dano(VARINHA_EPICO), ItemCriador.Nome(VARINHA_EPICO), ItemCriador.Peso(VARINHA_EPICO), ItemCriador.Cura(VARINHA_EPICO), ItemCriador.Defesa(VARINHA_EPICO)};
   
    pocaoDeCura_comum = {ItemCriador.Dano(POCAODECURA_COMUM), ItemCriador.Nome(POCAODECURA_COMUM), ItemCriador.Peso(POCAODECURA_COMUM), ItemCriador.Cura(POCAODECURA_COMUM), ItemCriador.Defesa(POCAODECURA_COMUM)};
    pocaoDeCura_raro = {ItemCriador.Dano(POCAODECURA_RARO), ItemCriador.Nome(POCAODECURA_RARO), ItemCriador.Peso(POCAODECURA_RARO), ItemCriador.Cura(POCAODECURA_RARO), ItemCriador.Defesa(POCAODECURA_RARO)};
    pocaoDeCura_lendario = {ItemCriador.Dano(POCAODECURA_LENDARIO), ItemCriador.Nome(POCAODECURA_LENDARIO), ItemCriador.Peso(POCAODECURA_LENDARIO), ItemCriador.Cura(POCAODECURA_LENDARIO), ItemCriador.Defesa(POCAODECURA_LENDARIO)};
    pocaoDeCura_epico = {ItemCriador.Dano(POCAODECURA_EPICO), ItemCriador.Nome(POCAODECURA_EPICO), ItemCriador.Peso(POCAODECURA_EPICO), ItemCriador.Cura(POCAODECURA_EPICO), ItemCriador.Defesa(POCAODECURA_EPICO)};

    vazio = {ItemCriador.Dano(VAZIO), ItemCriador.Nome(VAZIO), ItemCriador.Peso(VAZIO), ItemCriador.Cura(VAZIO), ItemCriador.Defesa(VAZIO)};

}


List::List(int maxList, int maxPeso)
{
    count = 0;
    head = NULL;
    Max = maxList;
    PesoMax = maxPeso;
}

List::~List(){
    ListPointer q;

    while(head!=NULL){
        q = head;
        head = head ->NextNode;
        delete q;
}

}

bool List::Empty(){
    return count == 0;
}

bool List::full(){
    return (count == Max);
}

bool List::fullPeso(){
    return ( Peso > PesoMax );
}

void List::Insert(CriandoItem x, int p){
    if(p < 1 || p > count+1){
        cout << "Posicao invalida"<<endl;
        return;
    }

    if(full()){
        cout << "O cinto esta cheio!" << endl;
        return;
    }

    Peso = Peso + x.Peso;

    if(fullPeso()){
        cout << "O cinto ira ficar pesado demais!"<<endl;
        Peso = Peso - x.Peso;
        return;
    }

    ListNode *newNode;
    newNode = new ListNode;
    if (newNode == NULL){
        cout << "sem espaco para o novo elemento"<<endl;
        return;
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

void List::Delete(CriandoItem &x, int p){

    if (p < 1 || p > count ){

        cout<<"posicao invalida"<< endl;
        return;
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

void List::Replace(CriandoItem x, int p, int &statusPeso){
    if (p < 1 || p > count){
        cout<<"posicao invalida"<< endl;
        return;
    }

    ListNode *Node;
    int opc;

    SetPosition(p, Node);

    Peso = Peso - Node->Entry.Peso;
    Peso = Peso + x.Peso;

    if(fullPeso()){
        Peso = Peso - x.Peso;
        Peso = Peso + Node->Entry.Peso;
        statusPeso = 0;
        return;
    }else{
        statusPeso = 1;
        Node-> Entry = x;
    }


}

void List::Retrieve(CriandoItem &x, int p){
    if (p < 1 || p > count){
        cout<< "posicao invalida"<< endl;
        return;
    }

    ListNode *Node;
    SetPosition(p, Node);
    x = Node -> Entry;
}

void List::ExibirList(){
    ListNode *q = head;
    for(int i = 0; i < Max; i++){
        if( i < count){
            cout << i + 1 << " - " << q->Entry.Nome << endl;
            q = q -> NextNode;
        }else{
            cout << i + 1 << " - " << "vazio"<<endl;
        }
        
    }


}

int List::Size(){
    return Max;
}

int List::PesoAtual(){
    return Peso;
}

// Stack Mochila

Mochila::Mochila(){
    top = NULL;
}

Mochila::~Mochila(){
    CriandoItem x;
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

void Mochila::Push(CriandoItem x){
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

void Mochila::Pop(CriandoItem &x) { 
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

    CriandoItem x;
    while(! Empty()){
         Pop(x);
    }
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

void Mochila::Top(CriandoItem &x){ 
    if(Empty()){ 
        cout << "Pilha vazia";
    }

    Pop(x);
    Push(x);
}


Heroi::Heroi(int vidaInicial, string nome, int capacidadeCinto, int pesoMaxCinto) : vida(vidaInicial), Nome(nome), mochila(), cinto(capacidadeCinto, pesoMaxCinto)
{}

int& Heroi::vidaHeroi(){
    return vida;
}

Mochila& Heroi::mochilaHeroi(){
    return mochila;
}

List& Heroi::cintoHeroi(){
    return cinto;
}

CriandoItem& Heroi::maoHeroi(){
    return Mao;
}

string& Heroi::exibindoNome(){
    return Nome;
}

void Heroi::curandoHeroi(CriandoItem &x){
    vida = vida + x.Cura;
    if(vida > 100){
        vida = 100;
    }
}

void Heroi::dandoDanoNoHeroi(CriandoInimigo &x){
    vida = vida - x.dano;
    if(vida < 0){
        vida = 0;
    }
}

// Funções inimigos, declaração de valores e estruturas.

Inimigo_generico::Inimigo_generico(){
    iniciandoInimigo();
}

void Inimigo_generico::iniciandoInimigo() {
    // Inimigos Simples do Mapa;
    inimigos[TIPO1] = {"Fenix - Lendaria", 5, 1, 1, 1}; // Vida definida como 1
    inimigos[TIPO2] = {"Soldado - Desolado", 3, 1, 1, 1}; // Vida definida como 1
    inimigos[TIPO3] = {"Mago - Renegado", 4, 1, 1, 1}; // Vida definida como 1
    inimigos[TIPO4] = {"Alma do soldado - Traido", 4, 1, 1, 1}; // Vida definida como 1

    inimigos[TIPO5] = {"Piratas - Amaldicoados", 6, 1, 2, 1}; // Vida definida como 1
    inimigos[TIPO6] = {"Soldados - Elite", 7, 1, 2, 1}; // Vida definida como 1
    inimigos[TIPO7] = {"Polvo de mil tentaculos", 9, 1, 2, 1}; // Vida definida como 1
    inimigos[TIPO8] = {"Espioes - sabotadores", 9, 1, 2, 1}; // Vida definida como 1

    inimigos[TIPO9] = {"Ermesz - Guardiao", 12, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO10] = {"Alithko - Devorador de pesadelos", 13, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO11] = {"Xerxes - O reflexo", 15, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO12] = {"Ezreal - O mago", 15, 1, 4, 1}; // Vida definida como 1

    inimigos[TIPO13] = {"Rei do mortos", 12, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO14] = {"Ezio - Devorador de almas", 13, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO15] = {"Dracula - O Rei", 15, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO16] = {"Orgne - O pesadelo", 15, 1, 4, 1}; // Vida definida como 1

    inimigos[TIPO17] = {"Golem - O Desolado", 12, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO18] = {"Andariel - Devorador de memorias", 13, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO19] = {"Astaroth - Manipulador", 15, 1, 4, 1}; // Vida definida como 1
    inimigos[TIPO20] = {"Gabriel - O Anjo Caido", 15, 1, 4, 1}; // Vida definida como 1

    inimigos[BOSS1] = {" Arcanjo - Sargento ", 18, 1, 5, 1}; // Vida definida como 1
    inimigos[BOSS2] = {" Paladino - Capitao", 20, 1, 5, 2}; // Vida definida como 1
    inimigos[BOSS3] = {" Hidra - Coronel", 25, 1, 5, 3}; // Vida definida como 1
    inimigos[BOSS4] = {" Lilith - Rainha das trevas ", 28, 1, 5, 4}; // Vida definida como 1
    inimigos[BOSS5] = {"Byuuri", 30, 1, 5, 5}; // Vida definida como 1
}

int Inimigo_generico::dano(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].dano;
}

string Inimigo_generico::nome(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].nome;
}

int Inimigo_generico::lvl_inimigo(TipoInimigo tipoInimigo) const{
    return inimigos[tipoInimigo].lvl;
}

int Inimigo_generico::sqm_lvl(TipoInimigo tipoInimigo) const{
    return inimigos[tipoInimigo].sqm_level;
}

int Inimigo_generico::barraVida(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].barraVida;
}

void Inimigo_generico::sofrendoDano(CriandoInimigo &inimigo, CriandoItem &item){
     inimigo.barraVida = inimigo.barraVida - item.Dano;
     if(inimigo.barraVida < 0){
        inimigo.barraVida = 0;
     }
     
} 



#endif