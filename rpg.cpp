#include "rpg.h"
#include <iostream>
#include<string>
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
CriandoItem pocaoSorte_comum;
CriandoItem pocaoSorte_raro;
CriandoItem pocaoSorte_lendario;
CriandoItem pocaoSorte_epico;
CriandoItem pocaoDeCura_comum;
CriandoItem pocaoDeCura_raro;
CriandoItem pocaoDeCura_lendario;
CriandoItem pocaoDeCura_epico;
CriandoItem pocaoDeDefesa_comum;
CriandoItem pocaoDeDefesa_raro;
CriandoItem pocaoDeDefesa_lendario;
CriandoItem pocaoDeDefesa_epico;
CriandoItem pocaoDePoder_comum;
CriandoItem pocaoDePoder_raro;
CriandoItem pocaoDePoder_lendario;
CriandoItem pocaoDePoder_epico;

// Chamando a função void:

Item::Item(){
    IniciandoItem();
}

void Item::IniciandoItem() {

    itens[POCAODASORTE_COMUM] = {10, "Porcao Sorte - Comum", 10, 10, 0};
    itens[POCAODASORTE_RARO] = {10, "Porcao Sorte - Raro", 10, 10, 0};
    itens[POCAODASORTE_LENDARIO] = {10, "Porcao Sorte - Lendario", 10, 10, 0};
    itens[POCAODASORTE_EPICO] = {10, "Porcao Sorte - Epico", 10, 10, 0};

    itens[POCAODECURA_COMUM] = {0, "Pocao Cura - Comum", 15, 30, 0};
    itens[POCAODECURA_RARO] = {0, "Pocao Cura - Raro", 17, 35, 0};
    itens[POCAODECURA_LENDARIO] = {0, "Pocao Cura - Lendario", 17, 40, 0};
    itens[POCAODECURA_EPICO] = {0, "Pocao Cura - Epico", 20, 60, 0};

    itens[POCAODEDEFESA_COMUM] = {0, "Pocao defesa - Comum", 20, 0, 30};
    itens[POCAODEDEFESA_RARO] = {0, "Pocao defesa - Raro", 20, 0, 30};
    itens[POCAODEDEFESA_LENDARIO] = {0, "Pocao defesa - Lendario", 20, 0, 30};
    itens[POCAODEDEFESA_EPICO] = {0, "Pocao defesa - Epico", 20, 0, 30};

    itens[POCAODEPODER_COMUM] = {10, "Pocao Poder - Comum", 30, 10, 10};
    itens[POCAODEPODER_RARO] = {10, "Pocao Poder - Raro", 30, 10, 10};
    itens[POCAODEPODER_LENDARIO] = {10, "Pocao Poder - Lendario", 30, 10, 10};
    itens[POCAODEPODER_EPICO] = {10, "Pocao Poder - Epico", 30, 10, 10};

    itens[ESPADA_COMUM] = {25, "Espada - Comum", 25, 0, 0};
    itens[ESPADA_RARO] = {25, "Espada - Raro", 25, 0, 0};
    itens[ESPADA_LENDARIO] = {25, "Espada - Lendario", 25, 0, 0};
    itens[ESPADA_EPICO] = {25, "Espada - Epico", 25, 0, 0};

    itens[MACHADO_COMUM] = {20, "Machado - Comum", 20, 0, 0};
    itens[MACHADO_RARO] = {20, "Machado - Raro", 20, 0, 0};
    itens[MACHADO_LENDARIO] = {20, "Machado - Lendario", 20, 0, 0};
    itens[MACHADO_EPICO] = {20, "Machado - Epico", 20, 0, 0};

    itens[VARINHA_COMUM] = {20, "Varinha - Comum", 20, 0, 0};
    itens[VARINHA_RARO] = {20, "Varinha - Raro", 20, 0, 0};
    itens[VARINHA_LENDARIO] = {20, "Varinha - Lendario", 20, 0, 0};
    itens[VARINHA_EPICO] = {20, "Varinha - Epico", 20, 0, 0};
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
   
    pocaoSorte_comum = {ItemCriador.Dano(POCAODASORTE_COMUM), ItemCriador.Nome(POCAODASORTE_COMUM), ItemCriador.Peso(POCAODASORTE_COMUM), ItemCriador.Cura(POCAODASORTE_COMUM), ItemCriador.Defesa(POCAODASORTE_COMUM)};
    pocaoSorte_raro = {ItemCriador.Dano(POCAODASORTE_RARO), ItemCriador.Nome(POCAODASORTE_RARO), ItemCriador.Peso(POCAODASORTE_RARO), ItemCriador.Cura(POCAODASORTE_RARO), ItemCriador.Defesa(POCAODASORTE_RARO)};
    pocaoSorte_lendario = {ItemCriador.Dano(POCAODASORTE_LENDARIO), ItemCriador.Nome(POCAODASORTE_LENDARIO), ItemCriador.Peso(POCAODASORTE_LENDARIO), ItemCriador.Cura(POCAODASORTE_LENDARIO), ItemCriador.Defesa(POCAODASORTE_LENDARIO)};
    pocaoSorte_epico = {ItemCriador.Dano(POCAODASORTE_EPICO), ItemCriador.Nome(POCAODASORTE_EPICO), ItemCriador.Peso(POCAODASORTE_EPICO), ItemCriador.Cura(POCAODASORTE_EPICO), ItemCriador.Defesa(POCAODASORTE_EPICO)};
    
    pocaoDeDefesa_comum = {ItemCriador.Dano(POCAODEDEFESA_COMUM), ItemCriador.Nome(POCAODEDEFESA_COMUM), ItemCriador.Peso(POCAODEDEFESA_COMUM), ItemCriador.Cura(POCAODEDEFESA_COMUM), ItemCriador.Defesa(POCAODEDEFESA_COMUM)};
    pocaoDeDefesa_raro = {ItemCriador.Dano(POCAODEDEFESA_RARO), ItemCriador.Nome(POCAODEDEFESA_RARO), ItemCriador.Peso(POCAODEDEFESA_RARO), ItemCriador.Cura(POCAODEDEFESA_RARO), ItemCriador.Defesa(POCAODEDEFESA_RARO)};
    pocaoDeDefesa_lendario = {ItemCriador.Dano(POCAODEDEFESA_LENDARIO), ItemCriador.Nome(POCAODEDEFESA_LENDARIO), ItemCriador.Peso(POCAODEDEFESA_LENDARIO), ItemCriador.Cura(POCAODEDEFESA_LENDARIO), ItemCriador.Defesa(POCAODEDEFESA_LENDARIO)};
    pocaoDeDefesa_epico = {ItemCriador.Dano(POCAODEDEFESA_EPICO), ItemCriador.Nome(POCAODEDEFESA_EPICO), ItemCriador.Peso(POCAODEDEFESA_EPICO), ItemCriador.Cura(POCAODEDEFESA_EPICO), ItemCriador.Defesa(POCAODEDEFESA_EPICO)};
    
    pocaoDeCura_comum = {ItemCriador.Dano(POCAODECURA_COMUM), ItemCriador.Nome(POCAODECURA_COMUM), ItemCriador.Peso(POCAODECURA_COMUM), ItemCriador.Cura(POCAODECURA_COMUM), ItemCriador.Defesa(POCAODECURA_COMUM)};
    pocaoDeCura_raro = {ItemCriador.Dano(POCAODECURA_RARO), ItemCriador.Nome(POCAODECURA_RARO), ItemCriador.Peso(POCAODECURA_RARO), ItemCriador.Cura(POCAODECURA_RARO), ItemCriador.Defesa(POCAODECURA_RARO)};
    pocaoDeCura_lendario = {ItemCriador.Dano(POCAODECURA_LENDARIO), ItemCriador.Nome(POCAODECURA_LENDARIO), ItemCriador.Peso(POCAODECURA_LENDARIO), ItemCriador.Cura(POCAODECURA_LENDARIO), ItemCriador.Defesa(POCAODECURA_LENDARIO)};
    pocaoDeCura_epico = {ItemCriador.Dano(POCAODECURA_EPICO), ItemCriador.Nome(POCAODECURA_EPICO), ItemCriador.Peso(POCAODECURA_EPICO), ItemCriador.Cura(POCAODECURA_EPICO), ItemCriador.Defesa(POCAODECURA_EPICO)};
}






// Lista Estatica:

Cinto::Cinto(){
    count = 0;
}

Cinto::~Cinto(){
    cout << "Cinto destruida";
}

bool Cinto::Empty(){
    return (count == 0);
}

bool Cinto::Full(){
    return (count == MaxList);
}

void Cinto::Insert(int p, CriandoItem x){ 
    int i;
    if (Full()){ 
        cout << "Cinto Cheia";
        return;
    }
    if (p < 1 || p > count+1){ 
        cout << "Posicao invalida";
        return;
    }
    for(i=count; i>=p; i--){
        Entry[i+1] = Entry[i];
    }
    Entry[p] = x;
    count++;
}

void Cinto::Delete(int p, CriandoItem &x){ 
    int i;
    if (Empty()){ 
        cout << "Cinto esta Vazia";
        return;
    }   
    if (p < 1 || p > count){ 
        cout << "Posicao invalida";
        return;
    }
    x = Entry[p];
    for(i=p; i<count; i++){
        Entry[i] = Entry[i+1];
    }
    count = count - 1;
        
}

void Cinto::Clear(){
    count = 0;
}

int Cinto::Size(){
    return count;
}

void Cinto::Retrieve(int p, CriandoItem&x){ 
    if(p < 1 || p > count){ 
        cout << "Posicao invalida";
        return;
    }
    x = Entry[p];

    cout << x.Nome << endl;
}

void Cinto::Replace(int p, CriandoItem x){ 
    if(p < 1 || p > count){ 
        cout << "Posicao invalida";
        return;
    }
    Entry[p] = x;
}

void Cinto::exibirCinto(){
    for(int i=0; i<count; i++){
        cout << "Posicao " << i << " " << Entry[i+1].Nome << endl;
    } cout << endl;
}



ListaItens::ListaItens(){
    count = 0;
}

ListaItens::~ListaItens(){
    cout << "Cinto destruida";
}

bool ListaItens::Empty(){
    return (count == 0);
}

bool ListaItens::Full(){
    return (count == MaxList);
}

void ListaItens::Insert(int p, CriandoItem x){ 
    int i;
    if (Full()){ 
        cout << "ListaItens Cheia";
        return;
    }
    if (p < 1 || p > count+1){ 
        cout << "Posicao invalida";
        return;
    }
    for(i=count; i>=p; i--){
        Entry[i+1] = Entry[i];
    }
    Entry[p] = x;
    count++;
}

void ListaItens::Delete(int p, CriandoItem &x){ 
    int i;
    if (Empty()){ 
        cout << "ListaItens esta Vazia";
        return;
    }   
    if (p < 1 || p > count){ 
        cout << "Posicao invalida";
        return;
    }
    x = Entry[p];
    for(i=p; i<count; i++){
        Entry[i] = Entry[i+1];
    }
    count = count - 1;
        
}

void ListaItens::Clear(){
    count = 0;
}

int ListaItens::Size(){
    return count;
}

void ListaItens::Retrieve(int p, CriandoItem&x){ 
    if(p < 1 || p > count){ 
        cout << "Posicao invalida";
        return;
    }
    x = Entry[p];

    cout << x.Nome << endl;
}

void ListaItens::Replace(int p, CriandoItem x){ 
    if(p < 1 || p > count){ 
        cout << "Posicao invalida";
        return;
    }
    Entry[p] = x;
}

void ListaItens::exibirListaItens(){
    for(int i=0; i<count; i++){
        cout << "Posicao " << i << " " << Entry[i+1].Nome << endl;
    } cout << endl;
}











// Stack Mochila

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





void Heroi::MostrandoTudo(){

cout<< "Name" << Name <<endl;
cout << " HP " << HP<<endl;
cout << "Ataque" << Ataque <<endl;
cout << "Defesa" << Defesa <<endl;
cout << "Agilidade" << Agilidade <<endl;
cout << "Luck" << Luck <<endl;
cout << "Especial" << Especial <<endl;

};

Heroi::Heroi (const string name, int hp, int ataque, int defesa, int agilidade, int luck, string especial):
Name (name), HP(hp), Ataque (ataque), Defesa (defesa), Agilidade (agilidade), Luck (luck), Especial (especial)
{
if (HP<0){ // fazendo verificacao da vida
    HP = 0;
};

if (HP>200) // verificacao da vida
{
    HP = 200;
};

};




#endif