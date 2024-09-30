#include "rpg.h"
#include <iostream>
#include<string>
using namespace std;
#ifndef RPG_H
#define RPG_H


// Classes de itens e seu atributos;

// Declarando as Structs para cada tipo de item (Coloquei tudo dentro de uma função void);
//Essa parte do código esta declarando varias instancias de um tipo chamado CriandoItem
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


/*
 Construtor da classe Item
  O construtor `Item::Item()` chama a função privada `IniciandoItem()` para preencher e inicializar os dados dos itens do jogo.
 */
Item::Item(){
    IniciandoItem();
}


/*
 Inicializa os itens com atributos como dano, nome, peso, cura e defesa.
 
 A função `IniciandoItem` é responsável por definir os atributos de cada item no jogo. Ela preenche o array `itens`.
 Poções de cura (com diferentes raridades, que variam de comum a lendario).
 Armas como espadas, machados e varinhas, cada uma também variando em raridade (comum, raro, lendário, épico).
 ou mesmo um item vazio
 
 Cada item é definido por cinco atributos:
 dano: O dano que o item pode causar (0 para poções de cura).
 nome: O nome do item.
 peso: O peso do item (usado para calcular os itens que o personagem pode carregar).
 cura: Quantidade de vida que o item pode curar.
 defesa: Nível de defesa que o item oferece.
 */
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

//Retorna o valor de dano causado pelo item de acordo com o tipo fornecido.
int Item::Dano(Tipo tipo) const {
    return itens[tipo].Dano;
}
//Retorna a quantidade de vida que o item pode restaurar.
int Item::Cura(Tipo tipo) const {
    return itens[tipo].Cura;
}
//Retorna o nome completo do item. 
string Item::Nome(Tipo tipo) const {
    return itens[tipo].Nome;
}
//Retorna o valor de defesa de um item.
int Item::Defesa(Tipo tipo) const {
    return itens[tipo].Defesa;
}
//Retorna o peso do item.
int Item::Peso(Tipo tipo) const {
    return itens[tipo].Peso;
}

// Função que irá atribuir os valores para cada tipo de item, o qual deve ser chamada no inicio do código, antes da chamada de todos os itens;

void criandoItens(){
 // Cria um objeto da classe Item para acessar os atributos dos itens.
    Item ItemCriador;

//    // Inicializa as espadas com seus respectivos atributos.
    espada_comum = {ItemCriador.Dano(ESPADA_COMUM), ItemCriador.Nome(ESPADA_COMUM), ItemCriador.Peso(ESPADA_COMUM), ItemCriador.Cura(ESPADA_COMUM), ItemCriador.Defesa(ESPADA_COMUM)};
    espada_raro = {ItemCriador.Dano(ESPADA_RARO), ItemCriador.Nome(ESPADA_RARO), ItemCriador.Peso(ESPADA_RARO), ItemCriador.Cura(ESPADA_RARO), ItemCriador.Defesa(ESPADA_RARO)};
    espada_lendario = {ItemCriador.Dano(ESPADA_LENDARIO), ItemCriador.Nome(ESPADA_LENDARIO), ItemCriador.Peso(ESPADA_LENDARIO), ItemCriador.Cura(ESPADA_LENDARIO), ItemCriador.Defesa(ESPADA_LENDARIO)};
    espada_epico = {ItemCriador.Dano(ESPADA_EPICO), ItemCriador.Nome(ESPADA_EPICO), ItemCriador.Peso(ESPADA_EPICO), ItemCriador.Cura(ESPADA_EPICO), ItemCriador.Defesa(ESPADA_EPICO)};
    
       // Inicializa os machados com seus respectivos atributos.
    machado_comum = {ItemCriador.Dano(MACHADO_COMUM), ItemCriador.Nome(MACHADO_COMUM), ItemCriador.Peso(MACHADO_COMUM), ItemCriador.Cura(MACHADO_COMUM), ItemCriador.Defesa(MACHADO_COMUM)};
    machado_raro = {ItemCriador.Dano(MACHADO_RARO), ItemCriador.Nome(MACHADO_RARO), ItemCriador.Peso(MACHADO_RARO), ItemCriador.Cura(MACHADO_RARO), ItemCriador.Defesa(MACHADO_RARO)};
    machado_lendario = {ItemCriador.Dano(MACHADO_LENDARIO), ItemCriador.Nome(MACHADO_LENDARIO), ItemCriador.Peso(MACHADO_LENDARIO), ItemCriador.Cura(MACHADO_LENDARIO), ItemCriador.Defesa(MACHADO_LENDARIO)};
    machado_epico = {ItemCriador.Dano(MACHADO_EPICO), ItemCriador.Nome(MACHADO_EPICO), ItemCriador.Peso(MACHADO_EPICO), ItemCriador.Cura(MACHADO_EPICO), ItemCriador.Defesa(MACHADO_EPICO)};
        
        // Inicializa as varinhas com seus respectivos atributos.
    Varinha_comum = {ItemCriador.Dano(VARINHA_COMUM), ItemCriador.Nome(VARINHA_COMUM), ItemCriador.Peso(VARINHA_COMUM), ItemCriador.Cura(VARINHA_COMUM), ItemCriador.Defesa(VARINHA_COMUM)};
    Varinha_raro = {ItemCriador.Dano(VARINHA_RARO), ItemCriador.Nome(VARINHA_RARO), ItemCriador.Peso(VARINHA_RARO), ItemCriador.Cura(VARINHA_RARO), ItemCriador.Defesa(VARINHA_RARO)};
    Varinha_lendario = {ItemCriador.Dano(VARINHA_LENDARIO), ItemCriador.Nome(VARINHA_LENDARIO), ItemCriador.Peso(VARINHA_LENDARIO), ItemCriador.Cura(VARINHA_LENDARIO), ItemCriador.Defesa(VARINHA_LENDARIO)};
    Varinha_epico = {ItemCriador.Dano(VARINHA_EPICO), ItemCriador.Nome(VARINHA_EPICO), ItemCriador.Peso(VARINHA_EPICO), ItemCriador.Cura(VARINHA_EPICO), ItemCriador.Defesa(VARINHA_EPICO)};
       
       // Inicializa as pocoes com seus respectivos atributos.
    pocaoDeCura_comum = {ItemCriador.Dano(POCAODECURA_COMUM), ItemCriador.Nome(POCAODECURA_COMUM), ItemCriador.Peso(POCAODECURA_COMUM), ItemCriador.Cura(POCAODECURA_COMUM), ItemCriador.Defesa(POCAODECURA_COMUM)};
    pocaoDeCura_raro = {ItemCriador.Dano(POCAODECURA_RARO), ItemCriador.Nome(POCAODECURA_RARO), ItemCriador.Peso(POCAODECURA_RARO), ItemCriador.Cura(POCAODECURA_RARO), ItemCriador.Defesa(POCAODECURA_RARO)};
    pocaoDeCura_lendario = {ItemCriador.Dano(POCAODECURA_LENDARIO), ItemCriador.Nome(POCAODECURA_LENDARIO), ItemCriador.Peso(POCAODECURA_LENDARIO), ItemCriador.Cura(POCAODECURA_LENDARIO), ItemCriador.Defesa(POCAODECURA_LENDARIO)};
    pocaoDeCura_epico = {ItemCriador.Dano(POCAODECURA_EPICO), ItemCriador.Nome(POCAODECURA_EPICO), ItemCriador.Peso(POCAODECURA_EPICO), ItemCriador.Cura(POCAODECURA_EPICO), ItemCriador.Defesa(POCAODECURA_EPICO)};
        
        // Inicializa um item vazio, sem atributos.
    vazio = {ItemCriador.Dano(VAZIO), ItemCriador.Nome(VAZIO), ItemCriador.Peso(VAZIO), ItemCriador.Cura(VAZIO), ItemCriador.Defesa(VAZIO)};

}


List::List(int maxList, int maxPeso) // chamando a List da classe list
{
    count = 0;
    head = NULL;
    Max = maxList;
    PesoMax = maxPeso;
}

List::~List(){ // destrutor da List
    ListPointer q; // ponteiro q

    while(head!=NULL){
        q = head;
        head = head ->NextNode; 
        delete q;
}

}

bool List::Empty(){ // verificando se esta vazio
    return count == 0;
}

bool List::full(){ 
    return (count == Max);
}

bool List::fullPeso(){  //verificando o peso
    return ( Peso > PesoMax );
}

void List::Insert(CriandoItem x, int p){ // inserindo intens no cinto
    if(p < 1 || p > count+1){
        cout << "Posicao invalida"<<endl;
        return;
    }

    if(full()){ //verifica se o cinto ta cheio
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
// Atribui o valor x ao campo Entry do novo nó, newNode
    newNode -> Entry = x; 

    //Verifica se p == 1, ou seja, se o nó deve ser inserido na primeira posição da lista.
    if (p == 1){
        newNode-> NextNode = head;
        head = newNode;
    //Declara um ponteiro q do tipo ListNode, que será usado para rastrear o nó anterior à posição onde o novo nó será inserido
    }else{
        ListNode  *q;
        SetPosition(p - 1, q);
        newNode -> NextNode = q -> NextNode;
        q -> NextNode = newNode;
    }

    count ++; //contador aumenta
}

void List::Delete(CriandoItem &x, int p){ //implementando um delete

    if (p < 1 || p > count ){ //Verifica se a posição p passada é válida.

        cout<<"posicao invalida"<< endl;
        return;
    }

    ListNode *Node; 
    //Caso p == 1, significa que o nó a ser removido está na primeira posição.
    if (p == 1){
        Node = head;
        head = head-> NextNode;
        
    }else{
        ListNode *q;
        SetPosition(p-1, q);
        Node = q -> NextNode;
        
        q -> NextNode = Node -> NextNode;  

    }
    //Atribui os dados do nó (Node->Entry) ao parâmetro x, permitindo que os dados removidos sejam acessados fora da função
    x = Node -> Entry;
    delete Node; //Usa delete para liberar a memória ocupada por Node
    count -- ;
}

void List::SetPosition(int p, ListPointer &current){
    current = head;
    //Um loop for percorre a lista até encontrar a posição p. A cada iteração, current avança para o próximo nó da lista
    for(int i = 2; i <= p; i++){
        current = current -> NextNode;

    }
}

void List::Clear(){ // implementando uma funcao para limpar 
    ListNode *q;
    while(head != NULL ){
        q = head;
        head = head -> NextNode;
        delete q;
    }
    count = 0;
}
//Validação da Posição: A função começa verificando se o valor de p está fora dos limites da lista.
void List::Replace(CriandoItem x, int p, int &statusPeso){
    if (p < 1 || p > count){
        cout<<"posicao invalida"<< endl;
        return;
    }
//declarando um novo no
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
//Validação da Posição: A função começa verificando se o valor de p está fora dos limites da lista.
void List::Retrieve(CriandoItem &x, int p){
    if (p < 1 || p > count){
        cout<< "posicao invalida"<< endl;
        return;
    }
//Um ponteiro Node do tipo ListNode é declarado para armazenar o nó correspondente a posição p da lista.
    ListNode *Node;
    SetPosition(p, Node);
    x = Node -> Entry;
}

void List::ExibirList(){
    //Inicialização do Ponteiro: Um ponteiro q do tipo ListNode é inicializado com o valor de head
    ListNode *q = head;
    for(int i = 0; i < Max; i++){
        // if verifica se a posição atual i é menor que count, que representa o número de elementos atualmente armazenados na lista.
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

void Mochila::Push(CriandoItem x){ // retira elemento
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

void Mochila::Clear(){  // verifica se a michila ta vazia

    CriandoItem x;
    while(! Empty()){
         Pop(x);
    }
}

int Mochila::Size(){ //tamanho da michila
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

    Pop(x); //retira
    Push(x); // insere
}

//contrutor da classe heroi inicializando
Heroi::Heroi(int vidaInicial, string nome, int capacidadeCinto, int pesoMaxCinto) : vida(vidaInicial), Nome(nome), mochila(), cinto(capacidadeCinto, pesoMaxCinto)
{}

int& Heroi::vidaHeroi(){ // vida do heroi
    return vida;
}

Mochila& Heroi::mochilaHeroi(){ //implementando a mochila
    return mochila;
}

List& Heroi::cintoHeroi(){ //cinto do heroi
    return cinto;
}

CriandoItem& Heroi::maoHeroi(){ // o que tem na mao do heroi
    return Mao;
}

string& Heroi::exibindoNome(){ // nome do heroi
    return Nome;
}

void Heroi::curandoHeroi(CriandoItem &x){ // cura quando usa pocao
    vida = vida + x.Cura;
    if(vida > 100){
        vida = 100;
    }
}

void Heroi::dandoDanoNoHeroi(CriandoInimigo &x){ // representa o dano do heroi
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
//Metodo dano: Retorna o valor de dano de um inimigo específico, pelo tipoInimigo
int Inimigo_generico::dano(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].dano;
}
//Metodo nome: Retorna o nome do inimigo correspondente ao tipo fornecido.
string Inimigo_generico::nome(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].nome;
}
//Metodo lvl_inimigo: Retorna o nível do inimigo.
int Inimigo_generico::lvl_inimigo(TipoInimigo tipoInimigo) const{
    return inimigos[tipoInimigo].lvl;
}
//Metodo sqm_lvl: Retorna o nível de experiência (sqm).
int Inimigo_generico::sqm_lvl(TipoInimigo tipoInimigo) const{
    return inimigos[tipoInimigo].sqm_level;
}
//Metodo barraVida: Retorna a quantidade de vida restante do inimigo
int Inimigo_generico::barraVida(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].barraVida;
}
//Método sofrendoDano:
//Atualiza a vida do inimigo subtraindo o dano causado pelo item.
void Inimigo_generico::sofrendoDano(CriandoInimigo &inimigo, CriandoItem &item){
     inimigo.barraVida = inimigo.barraVida - item.Dano;
     if(inimigo.barraVida < 0){
        inimigo.barraVida = 0;
     }
     
} 



#endif